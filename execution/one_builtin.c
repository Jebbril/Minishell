/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:55:14 by orakib            #+#    #+#             */
/*   Updated: 2023/05/30 17:03:38 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exec_onebuiltin(t_simple_cmd *command, t_env **envar, t_global *g_var)
{
	if (ft_strncmp(command->cmd[0], "cd", ft_strlen(command->cmd[0])) == 0
		&& ft_strncmp(command->cmd[0], "cd", 2) == 0)
		g_var->exit_code = m_cd(command->cmd, envar);
	if (ft_strncmp(command->cmd[0], "echo", ft_strlen(command->cmd[0])) == 0
		&& ft_strncmp(command->cmd[0], "echo", 4) == 0)
		g_var->exit_code = m_echo(command->cmd);
	if (ft_strncmp(command->cmd[0], "env", ft_strlen(command->cmd[0])) == 0
		&& ft_strncmp(command->cmd[0], "env", 3) == 0)
		g_var->exit_code = m_env(envar);
	if (ft_strncmp(command->cmd[0], "exit", ft_strlen(command->cmd[0])) == 0
		&& ft_strncmp(command->cmd[0], "exit", 4) == 0)
		g_var->exit_code = m_exit(command->cmd, g_var);
	if (ft_strncmp(command->cmd[0], "export", ft_strlen(command->cmd[0])) == 0
		&& ft_strncmp(command->cmd[0], "export", 5) == 0)
		g_var->exit_code = m_export(command->cmd, envar);
	if (ft_strncmp(command->cmd[0], "pwd", ft_strlen(command->cmd[0])) == 0
		&& ft_strncmp(command->cmd[0], "pwd", 3) == 0)
		g_var->exit_code = m_pwd();
	if (ft_strncmp(command->cmd[0], "unset", ft_strlen(command->cmd[0])) == 0
		&& ft_strncmp(command->cmd[0], "unset", 5) == 0)
		g_var->exit_code = m_unset(command->cmd, envar);
}

int	check_builtin(char *arg)
{
	if (ft_strncmp(arg, "cd", ft_strlen(arg)) == 0
		&& ft_strncmp(arg, "cd", 2) == 0)
		return (1);
	if (ft_strncmp(arg, "echo", ft_strlen(arg)) == 0
		&& ft_strncmp(arg, "echo", 4) == 0)
		return (1);
	if (ft_strncmp(arg, "env", ft_strlen(arg)) == 0
		&& ft_strncmp(arg, "env", 3) == 0)
		return (1);
	if (ft_strncmp(arg, "exit", ft_strlen(arg)) == 0
		&& ft_strncmp(arg, "exit", 4) == 0)
		return (1);
	if (ft_strncmp(arg, "export", ft_strlen(arg)) == 0
		&& ft_strncmp(arg, "export", 5) == 0)
		return (1);
	if (ft_strncmp(arg, "pwd", ft_strlen(arg)) == 0
		&& ft_strncmp(arg, "pwd", 3) == 0)
		return (1);
	if (ft_strncmp(arg, "unset", ft_strlen(arg)) == 0
		&& ft_strncmp(arg, "unset", 5) == 0)
		return (1);
	return (0);
}
