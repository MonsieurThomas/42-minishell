/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:19:26 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/25 14:26:51 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

void	ft_print_special(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '$') && (str[i + 1] == '?'))
		{
			printf("%d", g_global.ret_value);
			i++;
		}
		else if ((str[i] == '$') && (str[i + 1] == '$'))
		{
			printf("%d", getpid());
			i++;
		}
		else
			printf("%c", str[i]);
		i++;
	}
}

int	is_echo_special(char *str, t_data *data, int i)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if ((((str[j] == '$') && (str[j + 1] == '?')) || ((str[j] == '$')
					&& (str[j + 1] == '$'))) && ((data->lexer_type[i] != 2)
				&& (data->lexer_type[i] != 4)))
		{
			ft_print_special(str);
			return (0);
		}
		j++;
	}	
	return (1);
}

void	ft_echo_2nd(t_data *data, int i)
{
	while (data->lexer[i])
	{
		if (is_echo_special(data->lexer[i], data, i))
		{
			if (!ft_strncmp(data->lexer[i], "$?", 2)
				&& (ft_strlen(data->lexer[i]) == 2)
				&& ((data->lexer_type[i] != 2)
					&& (data->lexer_type[i] != 4)))
				printf("%d", g_global.ret_value);
			else
				printf("%s", data->lexer[i]);
		}
		if (data->lexer[i + 1] && data->lexer_type[i] <= 3)
			printf(" ");
		i++;
	}	
	if (data->echo_n == 0)
		printf("\n");
	g_global.ret_value = 0;
}

void	ft_echo(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	data->is_builtin++;
	data->echo_n = 0;
	while (!ft_strncmp(data->lexer[i], "-n", 2))
	{
		j = 1;
		while (data->lexer[i][j])
		{
			if (data->lexer[i][j] != 'n')
			{
				printf("%s", data->lexer[i]);
				data->echo_n--;
				if (data->lexer[i + 1])
					printf(" ");
				break ;
			}
			j++;
		}
		data->echo_n++;
		i++;
	}
	ft_echo_2nd(data, i);
}
