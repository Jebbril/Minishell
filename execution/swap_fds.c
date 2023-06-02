/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:51:58 by orakib            #+#    #+#             */
/*   Updated: 2023/06/02 16:16:04 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	swap_fds(t_simple_cmd *command)
{
	if (command->next || command->prev)
	{
		if (command->infd != command->instd)
		{
			command->instd = dup(command->instd);
			dup2(command->infd, 0);
			close(command->infd);
		}
	}
	if (command->outfd != command->outstd)
	{
		command->outstd = dup(command->outstd);
		dup2(command->outfd, 1);
		close(command->outfd);
	}
	return (0);
}

int	swap_fds_back(t_simple_cmd *command)
{
	if (command->infd != command->instd)
	{
		if (command->next || command->prev)
		{
			dup2(command->instd, 0);
			close(command->instd);
		}
	}
	if (command->outfd != command->outstd)
	{
		dup2(command->outstd, 1);
		close(command->outstd);
	}
	return (0);
}
