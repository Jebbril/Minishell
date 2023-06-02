/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:58:56 by orakib            #+#    #+#             */
/*   Updated: 2023/06/02 18:39:50 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cmd_execution(t_simple_cmd **cmds, t_env **envar, t_global *g_var)
{
	t_simple_cmd	*command;

	if (!cmds || !(*cmds) || cmds == (t_simple_cmd **)1)
		return ;
	command = *cmds;
	if (command->next == NULL)
	{
		if (!get_redirection(command))
		{
			if (command->cmd && command->cmd[0]
				&& check_builtin(command->cmd[0]))
			{
				swap_fds(command);
				exec_onebuiltin(command, envar, g_var);
				swap_fds_back(command);
			}
		}
		// swap_fds_back(command);
	}
}
