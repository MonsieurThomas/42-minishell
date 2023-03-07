/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_special_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:56:40 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/22 20:42:23 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

void	lexer_advance(t_data *lexer)
{
	if (lexer->c != '\0' && lexer->i < ft_strlen(lexer->contents))
	{
		lexer->i += 1;
		lexer->c = lexer->contents[lexer->i];
	}
}

void	lexer_skip_whitespace(t_data *lexer)
{
	while (lexer->c == ' ' || lexer->c == 10)
	{
		lexer_advance(lexer);
	}
}

void	init_lexer(char *contents, t_data *lexer)
{
	if (contents)
		lexer->contents = contents;
	lexer->i = 0;
	lexer->actual_i = 0;
	if (contents)
		lexer->c = contents[lexer->i];
	lexer->token_count = 0;
}

int	is_lexer_cursed(t_data *data, int j)
{
	if (data->contents[j] == '\'' && data->contents[j + 1])
	{
		j++;
		while (data->contents[j] && data->contents[j] != '\'')
			j++;
		return (j);
	}
	if (data->contents[j] == '"' && data->contents[j + 1])
	{
		j++;
		while (data->contents[j] && data->contents[j] != '"')
			j++;
		return (j);
	}
	return (j);
}
