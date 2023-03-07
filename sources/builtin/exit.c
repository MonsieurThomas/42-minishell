/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:19:56 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/22 14:52:01 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

int	isdigit_perso(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_data *data)
{
	data->is_builtin++;
	if (!data->lexer[1])
	{
		printf("exit\n");
		exit(1);
	}
	if (isdigit_perso(data->lexer[1]) && !data->lexer[2])
	{
		printf("exit\n");
		exit(ft_atoi(data->lexer[1]));
	}
	if ((isdigit_perso(data->lexer[1]) && data->lexer[2]))
	{
		printf("exit\nminishell: exit: too many arguments\n");
		g_global.ret_value = 1;
	}
	if (!isdigit_perso(data->lexer[1]))
	{
		printf("minishell: exit: %s", data->lexer[1]);
		printf(": numeric argument required\n");
		exit(255);
	}
}
