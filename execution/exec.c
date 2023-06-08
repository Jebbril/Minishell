/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:18:26 by edraidry          #+#    #+#             */
/*   Updated: 2023/06/08 18:19:27 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	close_fun(int fd)
{
	if (fd != 0 && fd != 1)
		close(fd);
}

void	ch_process(t_simple_cmd *command, char *av, char **env, t_fdvar fdvar)
{
	int	fd;

	fd = fork();
	if (fd == -1)
		ft_error("fork");
	if (fd == 0)
	{
		if (dup2 (fdvar.fdin, STDIN_FILENO) == -1)
			ft_error("fdinput");
		if (dup2 (fdvar.fdout, STDOUT_FILENO) == -1)
			ft_error("fdout");
		close_fun(fdvar.fdin);
		close_fun(fdvar.var);
		close_fun(fdvar.fdout);
		if (get_redirection(command))
			exit(1);
		swap_fds(command);
		if (check_builtin(command->cmd))
			exec_onebuiltin(command, get_envar(env));
		else
			ft_ex(av, env);
		exit(1);
	}		
}

void	p_process(char *av, char **env, t_fdvar fdvar)
{
	(void)av;
	(void)env;
	close_fun(fdvar.fdin);
	close_fun(fdvar.fdout);
}

void	ft_error(char *str)
{
	(void)str;
	perror (" ");
	exit(EXIT_FAILURE);
}
