/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:08:46 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/18 20:09:16 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

void	ft_cd_oldpwd(t_data *data, int i, int j, char *tmp)
{
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], "OLDPWD=", 7))
		{
			j = 0;
			while (data->env[j])
			{
				if (!ft_strncmp(data->env[j], "PWD=", 4))
				{
					free(data->env[i]);
					tmp = data->env[j];
					data->env[i] = ft_strjoin("OLD", tmp);
				}
				j++;
			}
		}
		i++;
	}
}

void	ft_cd_pwd(t_data *data, int i, char *tmp)
{
	while (data->env[i])
	{
		if (!ft_strncmp(data->env[i], "PWD=", 4))
		{
			free(data->env[i]);
			tmp = getcwd(NULL, 0);
			data->env[i] = ft_strjoin("PWD=", tmp);
			free(tmp);
		}
		i++;
	}
}

void	ft_cd(t_data *data)
{
	int		ret;
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	data->is_builtin++;
	ret = chdir(data->lexer[1]);
	if (!data->lexer[1])
		return ;
	if (ret == -1)
		printf("minishell: cd: %s: No such file or directory\n", data->lexer[1]);
	tmp = NULL;
	j = 0;
	ft_cd_oldpwd(data, i, j, tmp);
	i = 0;
	ft_cd_pwd(data, i, tmp);
	g_global.ret_value = 0;
}
