/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:26:08 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/19 18:23:15 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_simple_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	if (tab)
		free(tab);
}

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	if (data->contents)
		free(data->contents);
	if (data->lexer)
	{
		while (data->lexer[i])
		{
			free(data->lexer[i]);
			i++;
		}
	}
	if (data->lexer)
		free(data->lexer);
	if (data->lexer_type)
		free(data->lexer_type);
}
