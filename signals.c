/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:06:07 by edraidry          #+#    #+#             */
/*   Updated: 2023/06/09 17:43:24 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

//export LDFLAGS="-L/Users/edraidry/.brew/opt/readline/lib"
//export CPPFLAGS="-I/Users/edraidry/.brew/opt/readline/include"
static void    ft_control_c(int sig)
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
}

void    ft_control_quit(int sig)
{
    if (sig != SIGQUIT)
        return ;
    if (g_var.status == ISEXECUTING)
    {
        write(1, "\n", 1);
        exit(1);
    }
}

void ft_handler(void)
{
	signal(SIGINT, ft_control_c);
	signal(SIGQUIT, SIG_IGN);
}
