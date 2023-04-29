/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:46:01 by orakib            #+#    #+#             */
/*   Updated: 2023/04/29 17:24:03 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	fill_pnodes(t_lexer **thead, t_simple_cmd **phead)
{
	
}

int	create_pnodes(t_lexer **thead, t_simple_cmd **phead)
{
	t_lexer			*tnode;
	t_simple_cmd	*pnode;

	tnode = *thead;
	pnode = ft_newpnode();
	if (!pnode)
		return (1);
	ft_addpback(phead, pnode);
	while (tnode)
	{
		if (tnode->token == pipe)
		{
			pnode = ft_newpnode();
			if (!pnode)
				return (1);
			ft_addpback(phead, pnode);
		}
		tnode = tnode->next;
	}
	return (0);
}
