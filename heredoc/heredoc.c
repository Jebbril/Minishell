/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:49:37 by orakib            #+#    #+#             */
/*   Updated: 2023/05/17 18:04:04 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"



int	get_heredocs(t_simple_cmd **cmds)
{
	t_simple_cmd	*pnode;
	t_lexer			*tnode;
	int				i;

	pnode = *cmds;
	i = 1000000;
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
				
			}
			tnode = tnode->next;
		}
		pnode = pnode->next;
	}
	return (EXIT_SUCCESS);
}
