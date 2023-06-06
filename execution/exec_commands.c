/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:08:08 by orakib            #+#    #+#             */
/*   Updated: 2023/06/05 18:38:54 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exec_first_cmd(t_simple_cmd *command, t_env **envar, t_global *g_var,
		int *pipe)
{
	
}

void	exec_commands(t_simple_cmd **cmds, t_env **envar, t_global *g_var)
{
	t_simple_cmd	*command;
	int				pipe[2];

	command = *cmds;
	while (command)
	{
		if (command->prev == NULL)
			exec_first_cmd(command, envar, g_var, pipe);
		else if (command->next == NULL)
			exec_last_cmd(command, envar, g_var, pipe);
		else
			exec_middle_cmd(command, envar, g_var, pipe);
		command = command->next;
	}
}
