/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:02:48 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/18 18:57:31 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_export(char **env)
{
	int	i;

	i = 0;
	if (env)
	{
		while (env[i])
		{
			free(env[i]);
			i++;
		}
		free(env[i]);
		free(env);
	}
}

void	ft_export_only_export_part(char letter, t_data *data)
{
	int	j;

	letter = 'a';
	if (data->export)
	{
		while (letter != 'z')
		{
			j = -1;
			while (data->export[++j])
				if ((data->export[j][0] == letter)
					|| ((data->export[j][0] == letter - 32)))
					printf("declare -x %s\n", data->export[j]);
			letter++;
		}
	}	
}

int	ft_export_only(t_data *data)
{
	int		i;
	int		j;
	char	letter;

	i = 0;
	letter = 'a';
	if (!data->lexer[1])
	{
		while (letter != 'z')
		{
			j = -1;
			while (data->old_env[++j])
				if ((data->old_env[j][0] == letter)
					|| ((data->old_env[j][0] == letter - 32)))
					printf("declare -x %s\n", data->old_env[j]);
			letter++;
		}
		ft_export_only_export_part(letter, data);
		return (0);
	}
	return (1);
}

char	*export_add_guill(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	j = -1;
	tmp = malloc(sizeof(char) * (ft_strlen(str) + 3));
	while (str[++i])
	{
		tmp[++j] = str[i];
		if (str[i] == '=')
			tmp[++j] = '"';
		if (!str[i + 1])
			tmp[++j] = '"';
	}
	tmp[++j] = '\0';
	free(str);
	return (tmp);
}
