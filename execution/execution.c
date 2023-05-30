/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:58:56 by orakib            #+#    #+#             */
/*   Updated: 2023/05/30 17:05:30 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cmd_execution(t_simple_cmd **cmds, t_env **envar, t_global *g_var)
{
	t_simple_cmd	*command;

	command = *cmds;
	if (command->next == NULL)
	{
		if (command->cmd && check_builtin(command->cmd[0]))
			if (!get_redirection(command))
				exec_onebuiltin(command, envar, g_var);
	}
}
