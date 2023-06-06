/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:58:56 by orakib            #+#    #+#             */
/*   Updated: 2023/06/05 21:23:22 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cmd_execution(t_simple_cmd **cmds, t_env **envar, t_global *g_var)
{
	t_simple_cmd	*command;

	if (!cmds || !(*cmds) || cmds == (t_simple_cmd **)1)
		return ;
	command = *cmds;
	if (command->next == NULL && !get_redirection(command, g_var)
		&& command->cmd && command->cmd[0]
		&& check_builtin(command->cmd[0]))
	{
		swap_fds(command);
		exec_onebuiltin(command, envar, g_var);
		swap_fds_back(command);
		return ;
	}
	exec_commands(cmds, envar, g_var);
}
