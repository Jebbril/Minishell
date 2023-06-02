/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_hd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:38:55 by orakib            #+#    #+#             */
/*   Updated: 2023/06/02 15:53:20 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	unlink_hd(t_simple_cmd **cmds)
{
	t_simple_cmd	*pnode;
	t_lexer			*tnode;

	if (!cmds || !(*cmds) || cmds == (t_simple_cmd **)1)
		return ;
	pnode = *cmds;
	while (pnode)
	{
		if (!pnode->redirections)
			continue ;
		tnode = *(pnode->redirections);
		while (tnode)
		{
			if (tnode->token == here_doc)
			{
				tnode = tnode->next;
				if (tnode->token == w_space)
					tnode = tnode->next;
				unlink(tnode->str);
			}
			tnode = tnode->next;
		}
		pnode = pnode->next;
	}
}
