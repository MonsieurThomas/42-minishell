/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:48:50 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/22 20:30:43 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

void	lexer_collect_id_count(t_data *lexer)
{
	lexer_advance(lexer);
	while (lexer->c && lexer->c != ' ' && lexer->c != 10)
	{
		if (lexer->c == '\'')
		{
			lexer_advance(lexer);
			while (lexer->c && lexer->c != '\'')
				lexer_advance(lexer);
			lexer_advance(lexer);
		}	
		else if (lexer->c == '"')
		{
			lexer_advance(lexer);
			while (lexer->c && lexer->c != '"')
				lexer_advance(lexer);
			lexer_advance(lexer);
		}
		else if (lexer->c != ' ')
			lexer_advance(lexer);
	}
	(lexer->token_count) += 1;
}

void	lexer_collect_string_count(t_data *lexer)
{
	lexer_advance(lexer);
	while (lexer->c != '"')
		lexer_advance(lexer);
	lexer_advance(lexer);
	(lexer->token_count) += 1;
}

void	lexer_collect_string_count_bis(t_data *lexer)
{
	lexer_advance(lexer);
	while (lexer->c != '\'')
		lexer_advance(lexer);
	lexer_advance(lexer);
	(lexer->token_count) += 1;
}

void	count_token(t_data *lexer)
{
	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->contents))
	{
		if (lexer->c == ' ' || lexer->c == 10)
			lexer_skip_whitespace(lexer);
		if (lexer->c == '"')
			lexer_collect_string_count(lexer);
		if (lexer->c == '\'')
			lexer_collect_string_count_bis(lexer);
		if (lexer->c > 32 && lexer->c != '\'' && lexer->c != '"')
			lexer_collect_id_count(lexer);
	}
}

char	*lexer_get_next_token(t_data *lexer)
{
	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->contents))
	{
		if (lexer->c == ' ' || lexer->c == 10)
			lexer_skip_whitespace(lexer);
		if (lexer->c == '"')
			return (lexer_collect_string(lexer, '"'));
		if (lexer->c == '\'')
			return (lexer_collect_string(lexer, '\''));
		if (lexer->c > 32)
			return (lexer_collect_id(lexer));
	}
	return (0);
}
