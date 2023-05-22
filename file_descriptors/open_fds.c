/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_fds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:15:29 by orakib            #+#    #+#             */
/*   Updated: 2023/05/22 17:17:28 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	open_fds(t_simple_cmd **cmds)
{
	t_simple_cmd	*pnode;

	pnode = *cmds;
	while (pnode)
	{
		
		pnode = pnode->next;
	}
}