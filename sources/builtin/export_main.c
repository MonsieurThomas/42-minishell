/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:46:10 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/22 14:29:39 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

void	add_to_export_secret(t_data *data, int i, int j)
{
	if (ft_check_existence_export_export(data, j))
	{
		i = 0;
		if (data->export)
			while (data->export[i])
				i++;
		ft_export_export(data, i, j);
		g_global.ret_value = 0;
	}
}

int	ft_is_export_special_char(char c, char *s)
{
	if ((c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
	{
		printf("minishell: export: `%s': not a valid identifier\n", s);
		g_global.ret_value = 1;
		return (0);
	}
	return (1);
}

int	export_2nd_part(t_data *data, int i, int j)
{
	while (data->lexer[j][i] && data->lexer[j][i] != '=')
	{
		if (!ft_is_export_special_char(data->lexer[j][i], data->lexer[j]))
			return (0);
		i++;
	}
	if (data->lexer[j][i] == '=')
	{
		data->lexer[j] = ft_is_quote(data, j);
		if (!ft_check_existence_for_env(data, i, j))
		{
			ft_add_to_env(data, j);
			add_to_export(data, j);
			g_global.ret_value = 0;
		}
		if (data->is_in_env)
			ft_add_to_env(data, j);
	}
	else
		add_to_export_secret(data, i, j);
	return (1);
}

void	ft_export(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	data->is_builtin++;
	if (!(ft_export_only(data)))
		return ;
	while (data->lexer[++j])
	{
		i = 0;
		if (ft_isdigit(data->lexer[j][0]))
		{
			printf("minishell: export: `%s'", data->lexer[j]);
			printf(": not a valid identifier\n");
			g_global.ret_value = 1;
		}
		else
			export_2nd_part(data, i, j);
	}
}
