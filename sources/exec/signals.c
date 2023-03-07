/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:13:15 by rthomas           #+#    #+#             */
/*   Updated: 2022/07/19 18:19:27 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_glob	g_global;

void	show_ctl(int b)
{
	struct termios	new;

	tcgetattr(0, &new);
	if (b)
		new.c_lflag |= ECHOCTL;
	else
		new.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &new);
}

void	ft_sigint(void)
{
	if (g_global.pid != 0)
	{
		printf("\n");
		rl_redisplay();
		rl_on_new_line();
		kill(g_global.pid, 3);
	}
	else
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	ft_sigquit(void)
{
	if (g_global.pid != 0)
	{
		printf("Quit: 3\n");
		kill(g_global.pid, 3);
		g_global.ret_value = 131;
	}
	else
	{
		rl_on_new_line();
		rl_redisplay();
	}	
}

void	int_ft(int sig)
{
	if (sig == SIGINT)
	{
		ft_sigint();
	}
	if (sig == SIGQUIT)
	{
		ft_sigquit();
	}
}
