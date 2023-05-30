/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_hd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:38:55 by orakib            #+#    #+#             */
/*   Updated: 2023/05/30 10:35:36 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	unlink_hd(t_simple_cmd **cmds)
{
	t_simple_cmd	*pnode;
	t_lexer			*tnode;

	pnode = *cmds;
	while (pnode)
	{
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
