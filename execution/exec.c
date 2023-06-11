/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:18:26 by edraidry          #+#    #+#             */
/*   Updated: 2023/06/11 11:41:32 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	close_fun(int fd)
{
	if (fd != 0 && fd != 1)
		close(fd);
}

pid_t	ch_process(t_simple_cmd *command, char *av, char **env, t_fdvar fdvar)
{
	pid_t	fd;

	fd = fork();
	if (fd == -1)
		ft_error("fork", command);
	if (fd == 0)
	{
		signal(SIGQUIT, ft_control_quit);
		if (dup2 (fdvar.fdin, STDIN_FILENO) == -1)
			ft_error("fdinput", command);
		if (dup2 (fdvar.fdout, STDOUT_FILENO) == -1)
			ft_error("fdout", command);
		close_fun(fdvar.fdin);
		close_fun(fdvar.var);
		close_fun(fdvar.fdout);
		if (get_redirection(command))
			exit(g_var.exit_code);
		swap_fds(command);
		if (check_builtin(command->cmd))
			exec_onebuiltin(command, get_envar(env));
		else
			ft_ex(av, env, command);
		exit(g_var.exit_code);
	}
	return (fd);
}

void	p_process(char *av, char **env, t_fdvar fdvar)
{
	(void)av;
	(void)env;
	close_fun(fdvar.fdin);
	close_fun(fdvar.fdout);
}

void	ft_error(char *str, t_simple_cmd *command)
{
	if (!str && (!command->redirections || !(*(command->redirections))))
		write(2, "Command not found\n", 18);
	exit(EXIT_FAILURE);
}
