/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:58:56 by orakib            #+#    #+#             */
/*   Updated: 2023/06/08 16:40:38 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_size(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen_t(int size, char **strs, char *sep)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	while (i < size)
	{
		l += ft_strlen(strs[i]);
		i++;
	}
	l += ft_strlen(sep) * (size - 1);
	return (l);
}

char	*ft_strjoin2(int size, char **strs, char *sep)
{
	int		i;
	char	*tab;

	i = 1;
	if (size == 0)
	{
		tab = malloc(sizeof(char) * 1);
		*tab = 0;
		return (tab);
	}
	tab = (char *)malloc(sizeof(char) * (ft_strlen_t(size, strs, sep) + 1));
	if (tab == NULL)
		return (NULL);
	*tab = 0;
	ft_strcat(tab, strs[0]);
	while (i <= size - 1)
	{
		ft_strcat(tab, sep);
		ft_strcat(tab, strs[i]);
		i++;
	}
	return (tab);
}
/// 

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

void	cmd_execution(t_simple_cmd **cmds, t_env **envar)
{
	t_simple_cmd	*command;
	int				fd[2];
	char			**env;
	int				fdin;
	int				fdout;
	int				var;
	int				i;
	char			*str;

	if (!cmds || !(*cmds) || cmds == (t_simple_cmd **)1)
		return ;
	command = *cmds;
	if (command->next == NULL && !get_redirection(command)
		&& command->cmd && command->cmd[0]
		&& check_builtin(command->cmd[0]))
	{
		swap_fds(command);
		exec_onebuiltin(command, envar);
		swap_fds_back(command);
		return ;
	}
	i = 2;
	fdin = 0;
	fdout = 1;
	env = env_to_str(*envar);
	i = 0;
	while (command)
	{
		pipe (fd);
		var = fd[0];
		fdout = fd[1];
		if (!command->next)
			fdout = 1;
		str = ft_strjoin2(ft_size(command->cmd), command->cmd, " ");
		ch_process(command, str, env, fdin, fdout, var);
		p_process(str, env, fdin, fdout);
		fdin = fd[0];
		i++;
		command = command->next;
	}
	while (wait(NULL) != -1)
		;
	return ;
}
