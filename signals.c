/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:06:07 by edraidry          #+#    #+#             */
/*   Updated: 2023/06/14 18:08:43 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

static void	ft_control_c(int sig)
{
	if (sig != SIGINT)
		return ;
	if (g_var.status == ISREADING)
	{
		g_var.exit_code = 1;
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (g_var.status == ISHEREDOC)
	{
		rl_replace_line("", 0);
		write(1, "\n", 1);
		close(0);
		g_var.status = ISCONTROLC;
	}
}

void	ft_control_quit(int sig)
{
	if (sig != SIGQUIT)
		return ;
	if (g_var.status == ISEXECUTING)
	{
		write(1, "\n", 1);
		exit(1);
	}
}

void	ft_handler(void)
{
	signal(SIGINT, ft_control_c);
	signal(SIGQUIT, SIG_IGN);
}
