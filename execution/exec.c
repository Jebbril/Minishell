/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:18:26 by edraidry          #+#    #+#             */
/*   Updated: 2023/06/08 16:32:18 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	close_fun(int fd)
{
	if (fd != 0 && fd != 1)
		close(fd);
}

void	ch_process(t_simple_cmd *command, char *av, char **env,
		int fdin, int fdout, int var)
{
	int	fd;

	fd = fork();
	if (fd == -1)
		ft_error("fork");
	if (fd == 0)
	{
		if (dup2 (fdin, STDIN_FILENO) == -1)
			ft_error("fdinput");
		if (dup2 (fdout, STDOUT_FILENO) == -1)
			ft_error("fdout");
		close_fun(fdin);
		close_fun(var);
		close_fun(fdout);
		if (get_redirection(command))
			exit(1);
		swap_fds(command);
		if (command->cmd && command->cmd[0]
			&& check_builtin(command->cmd[0]))
			exec_onebuiltin(command, get_envar(env));
		else
			ft_ex(av, env);
		exit(1);
	}		
}

void	p_process(char *av, char **env, int fdin, int fdout)
{
	(void)av;
	(void)env;
	close_fun(fdin);
	close_fun(fdout);
}

void	ft_error(char *str)
{
	(void)str;
	perror (" ");
	exit(EXIT_FAILURE);
}
