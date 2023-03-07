/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:20:45 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/20 19:41:55 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern t_glob	g_global;

void	init_value(t_data *data)
{
	data->j = 0;
	data->k = 0;
	data->error = 0;
	data->is_builtin = 0;
	data->error_quote = 0;
	data->is_in_env = 0;
	data->is_touching = 0;
	data->lguill_i = 0;
	data->lguill_j = 0;
	data->export = NULL;
}

char	*get_env(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], str, ft_strlen(str)))
			return (ft_strdup(data->env[i] + (ft_strlen(str) + 1)));
		i++;
	}
	return (0);
}

void	init_env_and_value(char **env, t_data *data)
{
	int	i;

	i = 0;
	init_value(data);
	while (env[i])
		i++;
	data->env = malloc(sizeof(char *) * (i + 2));
	data->old_env = malloc(sizeof(char *) * (i + 2));
	ft_bzero(data->env, sizeof(char *) * (i + 1));
	ft_bzero(data->old_env, sizeof(char *) * (i + 1));
	data->env[i] = 0;
	data->old_env[i] = 0;
	i = 0;
	while (env[i])
	{
		data->env[i] = ft_strdup(env[i]);
		data->old_env[i] = ft_strdup(env[i]);
		i++;
	}
}
