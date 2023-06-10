/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:58:56 by orakib            #+#    #+#             */
/*   Updated: 2023/06/10 10:31:43 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**env_to_str(t_env *list)
{
	t_env	*tmp;
	char	**env;
	char	*str;
	int		i;

	i = 0;
	tmp = list;
	while (tmp && ++i)
		tmp = tmp->next;
	env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!env)
		return (NULL);
	env[i] = NULL;
	i = 0;
	while (list)
	{
		str = ft_strjoin(list->key, "=");
		env[i] = ft_strjoin(str, list->value);
		free(str);
		list = list->next;
		i++;
	}
	return (env);
}

void	wait_func(pid_t pid)
{
	waitpid(pid, &g_var.exit_code, 0);
	if (WIFEXITED(g_var.exit_code))
		g_var.exit_code = WEXITSTATUS(g_var.exit_code);
	else if (WIFSIGNALED(g_var.exit_code))
		g_var.exit_code = WTERMSIG(g_var.exit_code) + 128;
	while (wait(NULL) != -1)
		;
}

void	exec_cmds(t_env **envar, int *fd, t_simple_cmd *command)
{
	char			**env;
	t_fdvar			fdvar;
	char			*str;
	pid_t			pid;

	fdvar.fdin = 0;
	fdvar.fdout = 1;
	env = env_to_str(*envar);
	while (command)
	{
		pipe (fd);
		fdvar.var = fd[0];
		fdvar.fdout = fd[1];
		if (!command->next)
			fdvar.fdout = 1;
		str = ft_strjoin2(ft_size1(command->cmd), command->cmd, " ");
		pid = ch_process(command, str, env, fdvar);
		p_process(str, env, fdvar);
		fdvar.fdin = fd[0];
		command = command->next;
	}
	wait_func(pid);
}

void	cmd_execution(t_simple_cmd **cmds, t_env **envar)
{
	t_simple_cmd	*command;
	int				fd[2];

	if (!cmds || !(*cmds) || cmds == (t_simple_cmd **)1)
		return ;
	command = *cmds;
	if (command->next == NULL && !get_redirection(command)
		&& check_builtin(command->cmd))
	{
		swap_fds(command);
		exec_onebuiltin(command, envar);
		swap_fds_back(command);
		return ;
	}
	exec_cmds(envar, fd, command);
}
