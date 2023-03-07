/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:20:06 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/19 14:40:39 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

void	ft_unset_old_env(t_data *data)
{
	int		i;
	int		j;
	int		tmp;

	j = 0;
	while (data->lexer[++j])
	{
		i = -1;
		while (data->old_env[++i])
		{
			if ((!ft_strncmp(data->old_env[i], data->lexer[j],
						ft_strlen(data->lexer[j]))
					&& ft_strlen(data->lexer[j]) > 0)
				&& !ft_strchr(data->lexer[j], '='))
			{
				tmp = i;
				free(data->old_env[i]);
				i--;
				while (data->old_env[++i + 1])
					data->old_env[i] = data->old_env[i + 1];
				data->old_env[i] = NULL;
			}
		}
	}
}

void	ft_unset_remove_env(t_data *data, int i, int j)
{
	if ((!ft_strncmp(data->env[i], data->lexer[j],
				ft_strlen(data->lexer[j]))
			&& ft_strlen(data->lexer[j]) > 0)
		&& !ft_strchr(data->lexer[j], '='))
	{
		free(data->env[i]);
		while (data->env[i + 1])
		{
			data->env[i] = data->env[i + 1];
			i++;
		}
		data->env[i] = NULL;
	}
}

void	ft_unset_remove_export(t_data *data, int j)
{
	int	i;

	i = 0;
	if (data->export)
	{
		while (data->export[i])
		{
			if ((!ft_strncmp(data->export[i], data->lexer[j],
						ft_strlen(data->lexer[j]))
					&& ft_strlen(data->lexer[j]) > 0)
				&& ft_strchr(data->export[i], '='))
			{
				free(data->export[i]);
				while (data->export[i + 1])
				{
					data->export[i] = data->export[i + 1];
					i++;
				}
				data->export[i] = NULL;
			}
			i++;
		}
	}
}

void	ft_unset(t_data *data)
{
	int		i;
	int		j;

	data->is_builtin++;
	j = 1;
	while (data->lexer[j])
	{
		i = 0;
		while (data->env[i])
		{
			ft_unset_remove_env(data, i, j);
			ft_unset_remove_export(data, j);
			if (ft_strchr(data->lexer[j], '='))
			{
				printf("minishell: unset: `%s'", data->lexer[j]);
				printf(": not a valid identifier\n");
				break ;
			}
			i++;
		}
		j++;
	}
	ft_unset_old_env(data);
	g_global.ret_value = 0;
}
