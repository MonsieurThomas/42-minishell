/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:20:32 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/25 15:33:49 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

char	*find_path(char *cmd, t_data *data)
{
	data->j = -1;
	while (data->env[++data->j])
	{
		if (!ft_strncmp(data->env[data->j], "PATH=", 5))
		{
			data->path = data->env[data->j];
			data->env2 = ft_split(data->path + 5, ':');
			cmd = ft_strjoin("/", cmd);
			data->k = -1;
			while (data->env2 && data->env2[++data->k])
			{
				data->path = ft_strjoin(data->env2[data->k], cmd);
				if (access(data->path, F_OK) == 0)
				{
					free(cmd);
					return (data->path);
				}
				free(data->path);
			}
			ft_free_simple_tab(data->env2);
			return (NULL);
		}
	}
	return (NULL);
}

int	ft_is_path_legit(t_data *data)
{
	data->path = data->lexer[0];
	if (open(data->path, O_DIRECTORY) < 0 && data->path[0] == '/'
		&& access(data->path, F_OK) != 0)
	{
		printf("minishell: %s: Not a directory\n", data->path);
		exit(126);
	}
	if (access(data->path, F_OK) != 0)
	{
		printf("minishell: %s: No such file or directory\n", data->path);
		exit(127);
	}
	return (1);
}

int	exec(t_data *data)
{
	if (ft_strchr(data->lexer[0], '/'))
		ft_is_path_legit(data);
	else
			data->path = find_path(data->lexer[0], data);
	if (!data->path)
	{
		printf("minishell: %s: command not found \n", data->lexer[0]);
		exit(127);
	}
	if (open(data->path, O_DIRECTORY) > 0)
	{
		printf("minishell: %s: is a directory\n", data->path);
		exit(126);
	}
	if (execve(data->path, data->lexer, data->env) == -1)
	{
		printf("minishell: permission denied: %s\n", data->path);
		printf("Dans execve\n");
		exit(1);
	}
	free(data->path);
	free(data->lexer);
	return (1);
}

void	ft_exec_main(t_data *data)
{
	if (data->is_builtin > 0)
		return ;
	if (!data->lexer[0])
		return ;
	if (!is_special(data))
		return ;
	g_global.pid = fork();
	if (g_global.pid)
	{
		waitpid(-1, &g_global.status, 0);
		if (WIFEXITED(g_global.status))
			g_global.ret_value = WEXITSTATUS(g_global.status);
	}
	else
	{
		g_global.ret_value = 0;
		exec(data);
	}
	g_global.pid = 0;
}
