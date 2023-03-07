/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:01:34 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/25 14:26:25 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

char	*lexer_collect_string_2nd(t_data *lexer, char guill, char *s)
{
	int	a;

	lexer->j += lexer->i;
	lexer->i++;
	while (lexer->i < lexer->j)
	{
		s[lexer->k++] = lexer->contents[lexer->i];
		lexer_advance(lexer);
	}
	s[lexer->k] = '\0';
	lexer_advance(lexer);
	a = lexer->j;
	if (guill == '"')
	{
		lexer->lexer_type[lexer->actual_i] = 3;
		s = ft_isdollar_string(s, lexer, guill);
	}
	else
		lexer->lexer_type[lexer->actual_i] = 2;
	if (lexer->contents[a + 1] != ' ')
		lexer->lexer_type[lexer->actual_i] += 2;
	return (s);
}

char	*lexer_collect_string(t_data *lexer, char guill)
{
	char			*s;

	lexer->k = 0;
	lexer->j = lexer->i;
	lexer->j++;
	while (lexer->contents[lexer->j])
	{
		if (lexer->contents[lexer->j] == guill)
			break ;
		lexer->j++;
	}
	lexer->j -= lexer->i;
	s = malloc(sizeof(char) * (lexer->j + 1));
	s[lexer->j] = '\0';
	ft_bzero(s, lexer->j + 1);
	return (lexer_collect_string_2nd(lexer, guill, s));
}

char	*lexer_collect_id_2nd(int j, int k, t_data *lexer, char *s)
{
	while (lexer->i < j)
	{
		s[k] = lexer->contents[lexer->i];
		lexer_advance(lexer);
		k++;
	}
	s[k] = '\0';
	lexer->lexer_type[lexer->actual_i] = 1;
	s = ft_isdollar(s, lexer);
	return (ft_check_guill(s));
}

char	*lexer_collect_id(t_data *lexer)
{
	unsigned int	j;
	int				k;
	char			*s;

	lexer->isdollar = 0;
	k = 0;
	j = lexer->i;
	while (lexer->contents[j] && lexer->contents[j] != ' '
		&& lexer->contents[j] != 10)
	{
		j = is_lexer_cursed(lexer, j);
		j++;
	}
	j -= lexer->i;
	s = malloc(sizeof(char) * (j + 1));
	s[j] = '\0';
	j += lexer->i;
	return (lexer_collect_id_2nd(j, k, lexer, s));
}

void	lexer_main(t_data *data)
{
	int		i;

	init_lexer(data->contents, data);
	data->error_quote = 0;
	data->lexer = NULL;
	data->lexer_type = NULL;
	if (!count_quotes(data))
		return ;
	count_token(data);
	data->lexer = (char **)malloc(sizeof(char *) * (data->token_count + 1));
	data->lexer[data->token_count] = NULL;
	data->lexer_type = (int *)malloc(sizeof(int) * (data->token_count + 1));
	data->lexer_type[data->token_count] = 0;
	ft_bzero(data->lexer_type, data->token_count);
	ft_bzero(data->lexer, sizeof(char *) * data->token_count);
	data->i = 0;
	data->c = data->contents[0];
	i = -1;
	while (++i < data->token_count)
	{
		data->actual_i = i;
		data->lexer[i] = lexer_get_next_token(data);
	}
}
