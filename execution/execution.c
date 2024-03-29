/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:58:56 by orakib            #+#    #+#             */
/*   Updated: 2023/06/14 18:55:18 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_strjoin4(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = -1;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = 0;
	return (str);
}

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
		env[i] = ft_strjoin4(str, list->value);
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
		pid = ch_process(command, env, fdvar);
		p_process(env, fdvar);
		fdvar.fdin = fd[0];
		command = command->next;
	}
	error(env);
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
	if (command->next == NULL && command->redi_fail)
		return ;
	exec_cmds(envar, fd, command);
}
