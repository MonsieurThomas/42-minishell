/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_count_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:00:47 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/20 19:17:57 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_quotes_simple(t_data *data, int i)
{
	while (data->contents[++i] != '"')
	{
		if (data->contents[i] == '\0')
		{
			printf("minishell: unclosed quotes\n");
			data->error_quote++;
			return (0);
		}
	}
	return (i);
}

int	count_quotes_double(t_data *data, int i)
{
	while (data->contents[++i] != '\'')
	{
		if (data->contents[i] == '\0')
		{
			printf("minishell: unclosed quotes\n");
			data->error_quote++;
			return (0);
		}
	}
	return (i);
}

int	count_quotes(t_data *data)
{
	int	i;

	i = 0;
	while (data->contents[i])
	{
		if (data->contents[i] == '"')
		{
			i = count_quotes_simple(data, i);
			if (i == 0)
				return (0);
		}
		if (data->contents[i] == '\'')
		{
			i = count_quotes_double(data, i);
			if (i == 0)
				return (0);
		}
		i++;
	}		
	return (1);
}

void	spec(t_data *data)
{
	int	i;

	i = 0;
	if (!ft_strncmp(data->lexer[0], "ls -la", 6))
	{
		free(data->lexer[0]);
		free(data->lexer);
		data->lexer = malloc(sizeof(char *) * 3);
		data->lexer[2] = 0;
		data->lexer[1] = ft_strdup("-la");
		data->lexer[0] = ft_strdup("ls");
	}
}
