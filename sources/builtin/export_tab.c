/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:58:11 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/18 19:34:03 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_to_export_tab_2(char *tmp, t_data *data, char **tab, int i)
{
	tab[i] = ft_strdup(tmp);
	ft_free_export(data->export);
	data->export = malloc(sizeof(char *) * (i + 2));
	ft_bzero(data->export, sizeof(char *) * (i + 2));
	data->export[i + 1] = NULL;
	i = 0;
	while (tab[i])
	{
		data->export[i] = ft_strdup(tab[i]);
		i++;
	}
	ft_free_export(tab);
	free(tmp);
}

void	add_to_export_tab(t_data *data, char *tmp)
{
	int		i;
	char	**tab;

	i = 0;
	if (data->export)
		while (data->export[i])
			i++;
	tab = malloc(sizeof(char *) * (i + 2));
	ft_bzero(tab, sizeof(char *) * (i + 2));
	tab[i + 1] = NULL;
	i = 0;
	if (data->export)
	{
		while (data->export[i])
		{
			tab[i] = ft_strdup(data->export[i]);
			i++;
		}
	}
	add_to_export_tab_2(tmp, data, tab, i);
}

void	add_to_export(t_data *data, int j)
{
	int		i;
	int		k;
	char	*tmp;

	i = 0;
	k = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(data->lexer[j]) + 3));
	while (data->lexer[j][i])
	{
		tmp[k] = data->lexer[j][i];
		if (data->lexer[j][i] == '=')
		{
			k++;
			tmp[k] = '"';
		}
		if ((!data->lexer[j][i + 1]))
		{
			k++;
			tmp[k] = '"';
		}
		k++;
		i++;
	}
	tmp[k] = '\0';
	add_to_export_tab(data, tmp);
}

int	ft_check_existence_export_export(t_data *data, int j)
{
	int	k;

	k = 0;
	if (data->export)
	{
		while (data->export[k])
		{
			if (!ft_strncmp(data->lexer[j], data->export[k],
					ft_strlen(data->lexer[j])))
			{
				if (!ft_strchr(data->lexer[j], '='))
					return (0);
				free(data->export[k]);
				data->export[k] = ft_strdup(data->lexer[j]);
				return (0);
			}
			k++;
		}
	}
	return (1);
}

void	ft_export_export(t_data *data, int i, int j)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (i + 2));
	tab[i + 1] = 0;
	ft_bzero(tab, sizeof(char *) * (i + 2));
	i = 0;
	if (data->export)
	{
		while (data->export[i])
		{
			tab[i] = ft_strdup(data->export[i]);
			i++;
		}
	}
	tab[i] = ft_strdup(data->lexer[j]);
	ft_free_export(data->export);
	data->export = malloc(sizeof(char *) * (i + 2));
	ft_bzero(data->export, sizeof(char *) * (i + 2));
	i = 0;
	while (tab[i])
	{
		data->export[i] = ft_strdup(tab[i]);
		i++;
	}
	ft_free_export(tab);
}
