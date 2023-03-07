/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:20:03 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/13 20:06:54 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

void	ft_pwd(t_data *data)
{
	int		i;
	char	*tmp;
	int		is_ok;

	i = 0;
	data->is_builtin++;
	is_ok = 0;
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], "PWD=", 4))
		{
			tmp = ft_strdup(data->env[i] + 4);
			is_ok = 1;
		}
		i++;
	}
	if (is_ok == 0)
		tmp = getcwd(NULL, 0);
	printf("%s\n", tmp);
	free(tmp);
	g_global.ret_value = 0;
}
