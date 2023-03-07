/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_dollar_variable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:51:03 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/19 18:54:00 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

char	*ft_is_variable_2nd(char *s, t_data *data)
{
	while (s[data->ii] != '$')
	{
		data->new_s[data->ii] = s[data->ii];
		data->ii++;
	}
	data->k = data->ii;
	while (data->tmp[data->j + 1])
	{
		data->new_s[data->k] = data->tmp[data->j + 1];
		data->k++;
		data->j++;
	}
	data->ii++;
	while (ft_isalnum(s[data->ii]))
		data->ii++;
	while (s[data->ii])
	{
		data->new_s[data->k] = s[data->ii];
		data->k++;
		data->ii++;
	}
	return (s);
}

char	*ft_is_variable(char *s, t_data *data)
{
	data->is_entered = 1;
	data->tmp = ft_strdup(data->env[data->k]);
	data->new_s = malloc(sizeof(char *) * (ft_strlen(s)
				+ ft_strlen(data->tmp)));
	data->new_s[ft_strlen(s) + ft_strlen(data->tmp)] = '\0';
	ft_bzero(data->new_s, ft_strlen(s) + ft_strlen(data->tmp));
	data->j = (data->j - data->ii - 1);
	data->ii = 0;
	s = ft_is_variable_2nd(s, data);
	free(s);
	free(data->tmp);
	s = ft_strdup(data->new_s);
	free(data->new_s);
	data->ii = 0;
	data->k = 0;
	data->dl++;
	return (s);
}

char	*ft_no_variable(t_data *data, char *s)
{
	data->new_s = malloc(sizeof(char) * (ft_strlen(s) + 1));
	ft_bzero(data->new_s, (ft_strlen(s) + 1));
	data->ii = 0;
	while (s[data->ii] != '$')
	{
		data->new_s[data->ii] = s[data->ii];
		data->ii++;
	}
	data->j = data->ii;
	data->ii++;
	while (ft_isalnum(s[data->ii]))
		data->ii++;
	if (s[data->ii] != '\0')
	{
		while (s[data->ii])
			data->new_s[data->j++] = s[data->ii++];
	}
	data->new_s[data->j] = '\0';
	free(s);
	s = ft_strdup(data->new_s);
	free(data->new_s);
	return (s);
}
