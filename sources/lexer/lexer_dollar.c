/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:31:49 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/22 18:02:42 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_isdollar_2nd(char *s, t_data *data)
{
	data->ii = data->dl;
	data->j = data->ii + 1;
	while (ft_isalnum(s[data->j]) && s[data->j] != ' ')
		data->j++;
	data->k = -1;
	while (data->env[++(data->k)])
	{
		if (!ft_strncmp(data->env[data->k], s + (data->ii + 1),
				(data->j - data->ii - 1)) && (data->env[data->k][data->j
				- data->ii - 1] == '='))
			s = ft_is_variable(s, data);
	}
	if (data->is_entered != 1)
		s = ft_no_variable(data, s);
	return (s);
}

void	isdollar_cursed(char c, t_data *data)
{
	if (c == '\'')
	{
		if (data->is_cursed == 1)
			data->is_cursed = 0;
		else
			data->is_cursed = 1;
	}
}

int	ft_isdollar_extension(char *s, t_data *data)
{
	data->is_entered = 0;
	data->dl = 0;
	data->is_cursed = 0;
	if ((ft_strlen(s) == 1) && (s[0] == '$'))
		return (1);
	if (!ft_strncmp(s, "$?", 2) && ft_strlen(s))
		return (1);
	if (!ft_strncmp(s, "$$", 2) && ft_strlen(s))
		return (1);
	return (0);
}

char	*ft_isdollar(char *s, t_data *data)
{
	if (ft_isdollar_extension(s, data))
		return (s);
	while (s[data->dl])
	{
		isdollar_cursed(s[data->dl], data);
		if (!data->is_cursed)
		{
			if (s[data->dl] == '$')
			{
				if (!ft_strncmp(s + data->dl, "$?", 2))
					return (s);
				if (!ft_strncmp(s + data->dl, "$$", 2))
					return (s);
				else if (s[data->dl + 1] != ' ')
				{
					s = ft_isdollar_2nd(s, data);
					data->is_cursed = 0;
					data->dl = -1;
				}
			}
			data->is_entered = 0;
		}
			data->dl++;
	}
	return (s);
}

char	*ft_isdollar_string(char *s, t_data *data, char guill)
{
	if (ft_isdollar_extension(s, data))
		return (s);
	while (s[data->dl])
	{
		if (guill != '\'')
		{
			if (s[data->dl] == '$')
			{
				if (!ft_strncmp(s + data->dl, "$?", 2))
					return (s);
				if (!ft_strncmp(s + data->dl, "$$", 2))
					return (s);
				else if (s[data->dl + 1] != ' ')
				{
					s = ft_isdollar_2nd(s, data);
					data->is_cursed = 0;
					data->dl = -1;
				}
			}
			data->is_entered = 0;
		}
		data->dl++;
	}
	return (s);
}
