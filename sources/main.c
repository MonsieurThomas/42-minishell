/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:34:04 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/22 18:09:01 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_global;

void	ft_isbuiltin_2nd(t_data *data)
{
	if ((!ft_strncmp(data->lexer[0], "cd", 2)
			|| (!ft_strncmp(data->lexer[0], "CD", 2)))
		&& (ft_strlen(data->lexer[0]) == 2))
		ft_cd(data);
	if ((!ft_strncmp(data->lexer[0], "env", 3)
			|| (!ft_strncmp(data->lexer[0], "ENV", 3)))
		&& (ft_strlen(data->lexer[0]) == 3))
		ft_env(data);
	if ((!ft_strncmp(data->lexer[0], "unset", 5)
			|| (!ft_strncmp(data->lexer[0], "UNSET", 5)))
		&& (ft_strlen(data->lexer[0]) == 5))
		ft_unset(data);
	if ((!ft_strncmp(data->lexer[0], "export", 6)
			|| (!ft_strncmp(data->lexer[0], "EXPORT", 6)))
		&& (ft_strlen(data->lexer[0]) == 6))
		ft_export(data);
}

void	ft_isbuiltin(t_data *data)
{
	data->is_builtin = 0;
	if (data->lexer)
	{
		if ((!ft_strncmp(data->lexer[0], "echo", 4)
				|| (!ft_strncmp(data->lexer[0], "ECHO", 4)))
			&& (ft_strlen(data->lexer[0]) == 4))
			ft_echo(data);
		if ((!ft_strncmp(data->lexer[0], "pwd", 3)
				|| (!ft_strncmp(data->lexer[0], "PWD", 3)))
			&& (ft_strlen(data->lexer[0]) == 3))
			ft_pwd(data);
		if ((!ft_strncmp(data->lexer[0], "exit", 3)
				|| (!ft_strncmp(data->lexer[0], "EXIT", 3)))
			&& (ft_strlen(data->lexer[0]) == 4))
			ft_exit(data);
		ft_isbuiltin_2nd(data);
	}
}

void	ft_lexer(t_data *data)
{
	char	*tmp;

	data->lexer = NULL;
	tmp = readline("minishell> ");
	if (!tmp)
	{
		ft_putstr_fd("exit\n", 1);
		exit(1);
	}
	data->contents = ft_strdup(tmp);
	free(tmp);
	add_history (data->contents);
	lexer_main(data);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void) ac;
	(void) av;
	init_env_and_value(env, &data);
	signal(SIGINT, int_ft);
	signal(SIGQUIT, int_ft);
	while (42)
	{
		show_ctl(0);
		ft_lexer(&data);
		if (data.error_quote == 0)
		{
			show_ctl(1);
			g_global.pid = 0;
			ft_isbuiltin(&data);
			ft_exec_main(&data);
		}
		ft_free(&data);
	}
}
