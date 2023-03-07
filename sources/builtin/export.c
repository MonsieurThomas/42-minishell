/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:19:59 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/20 19:28:31 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

char	*ft_is_quote_2nd(t_data *data, int j, int k)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(data->lexer[j]) + 1));
	k = 0;
	while (data->lexer[j][k])
	{
		if (((data->lexer[j][k] == '"') || (data->lexer[j][k] == '\''))
				&& (data->lexer[j][k + 1]))
			k++;
		if (data->lexer[j][k] != '"')
		{
			tmp[i] = data->lexer[j][k];
			i++;
		}
		k++;
	}
	tmp[i] = '\0';
	free(data->lexer[j]);
	data->lexer[j] = ft_strdup(tmp);
	free(tmp);
	return (data->lexer[j]);
}

char	*ft_is_quote(t_data *data, int j)
{
	int		k;

	k = -1;
	while (data->lexer[j][++k])
	{
		if ((data->lexer[j][k] == '"') || (data->lexer[j][k] == '\''))
		{
			data->lexer[j] = ft_is_quote_2nd(data, j, k);
			break ;
		}
	}
	return (data->lexer[j]);
}

int	ft_check_existence_for_env_2nd_part(t_data *data, int i, int j, int is_good)
{
	int	k;

	k = 0;
	if (data->export)
	{
		while (data->export[k])
		{
			if (!ft_strncmp(data->lexer[j], data->export[k], i))
			{
				free(data->export[k]);
				data->export[k] = export_add_guill(ft_strdup(data->lexer[j]));
				is_good++;
				if (ft_strchr(data->lexer[j], '=') && is_good == 1)
					data->is_in_env++;
			}
			k++;
		}
	}
	return (is_good);
}

int	ft_check_existence_for_env(t_data *data, int i, int j)
{
	int	k;
	int	is_good;

	k = 0;
	is_good = 0;
	data->is_in_env = 0;
	while (data->env[k])
	{
		if (!ft_strncmp(data->lexer[j], data->env[k], i))
		{
			free(data->env[k]);
			data->env[k] = ft_strdup(data->lexer[j]);
			is_good++;
		}
		k++;
	}
	is_good += ft_check_existence_for_env_2nd_part(data, i, j, is_good);
	return (is_good);
}

void	ft_add_to_env(t_data *data, int j)
{
	char	**tmp;
	int		i;

	i = 0;
	while (data->env[i])
		i++;
	tmp = (char **)malloc(sizeof(char *) * (i + 2));
	tmp[i + 1] = 0;
	ft_bzero(tmp, sizeof(char *) * (i + 2));
	i = -1;
	while (data->env[++i])
		tmp[i] = ft_strdup(data->env[i]);
	tmp[i] = ft_strdup(data->lexer[j]);
	ft_free_export(data->env);
	data->env = malloc(sizeof(char *) * (i + 2));
	ft_bzero(data->env, sizeof(char *) * (i + 2));
	i = -1;
	while (tmp[++i])
		data->env[i] = ft_strdup(tmp[i]);
	ft_free_export(tmp);
}
