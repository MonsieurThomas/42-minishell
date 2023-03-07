/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_special_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:55:18 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/25 15:38:18 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

int	is_special_random(t_data *data)
{
	if ((!ft_strncmp(data->contents, "\"\"", 2))
		&& ((ft_strlen(data->contents) == 2)
			|| (ft_strlen(data->contents) == 4)
			|| (ft_strlen(data->contents) == 6)))
	{
		printf("minishell: : command not found\n");
		g_global.ret_value = 127;
		return (0);
	}
	if ((!ft_strncmp(data->contents, "''", 2))
		&& ((ft_strlen(data->contents) == 2)
			|| (ft_strlen(data->contents) == 4)
			|| (ft_strlen(data->contents) == 6)))
	{
		printf("minishell: : command not found\n");
		g_global.ret_value = 127;
		return (0);
	}
	if (data->lexer[0][0] == '*' && (ft_strlen(data->lexer[0]) == 1))
	{
		printf("minishell: Applications: command not found\n");
		g_global.ret_value = 127;
		return (0);
	}
	return (1);
}

int	is_unexepted_token(t_data *data)
{
	char	c;

	c = data->lexer[0][0];
	if (c == '!' || c == '&' || c == ')' || c == ';'
		|| c == '}' || c == '|')
	{
		printf("minishell: syntax error near unexpected token `%c'\n", c);
		g_global.ret_value = 258;
		return (0);
	}
	if (c == '<' || c == '>')
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		g_global.ret_value = 258;
		return (0);
	}
	if (c == '%')
	{
		printf("minishell: bash: fg: %s: no such job\n", data->lexer[0]);
		g_global.ret_value = 1;
		return (0);
	}
	return (1);
}

void	is_special_2(t_data *data)
{
	int	i;

	i = -1;
	printf("minishell: ");
	while (data->lexer[0][++i])
	{
		if (data->lexer[0][i] == '$' && data->lexer[0][i + 1] == '?')
		{
			printf("%d", g_global.ret_value);
			i++;
		}
		else if (data->lexer[0][i] == '$' && data->lexer[0][i + 1] == '$')
		{
			printf("%d", getpid());
			i++;
		}
		else
			printf("%c", data->lexer[0][i]);
	}	
	printf(": command not found\n");
	g_global.ret_value = 127;
}

int	is_special(t_data *data)
{
	int	i;

	i = -1;
	while (data->lexer[0][++i])
	{
		if (data->lexer[0][i] == '$' && (data->lexer[0][i + 1]
			== '?' || data->lexer[0][i + 1] == '$'))
		{
			is_special_2(data);
			return (0);
		}
	}
	if (!is_unexepted_token(data))
		return (0);
	if (!is_special_random(data))
		return (0);
	spec(data);
	return (1);
}
