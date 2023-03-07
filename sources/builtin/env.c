/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:23:11 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/18 21:07:21 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

void	ft_env(t_data *data)
{
	int	i;

	i = 0;
	data->is_builtin++;
	while (data->env[i])
	{
		printf("%s\n", data->env[i]);
		i++;
	}
	g_global.ret_value = 0;
}
