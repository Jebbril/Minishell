/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:33:41 by orakib            #+#    #+#             */
/*   Updated: 2023/05/17 13:33:43 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/concat.h"

void	get_cmds22(t_lexer **tnode, t_simple_cmd **pnode, int i)
{
	while ((*tnode))
	{
		if ((*tnode)->token == word || (*tnode)->token == sq_word
			|| (*tnode)->token == dbq_word)
		{
			(*pnode)->cmd[i] = (*tnode)->str;
			(*tnode)->str = NULL;
			i++;
		}
		if ((*tnode)->token == pipe || (*tnode)->next == NULL)
		{
			(*pnode) = (*pnode)->next;
			(*tnode) = (*tnode)->next;
			i = 0;
		}
		else if ((*tnode))
			(*tnode) = (*tnode)->next;
	}
}

int	get_cmds2(t_lexer **thead, t_simple_cmd **phead)
{
	t_simple_cmd	*pnode;
	t_lexer			*tnode;
	int				i;

	pnode = *phead;
	tnode = *thead;
	i = 0;
	while (pnode)
	{
		get_cmds22(&tnode, &pnode, i);
		if (!tnode)
			break ;
	}
	return (0);
}

int	get_cmds12(t_lexer **tnode, t_simple_cmd **pnode, int i)
{
	while (*tnode)
	{
		if ((*tnode)->token == word || (*tnode)->token == sq_word
			|| (*tnode)->token == dbq_word)
			i++;
		if ((*tnode)->token == pipe || (*tnode)->next == NULL)
		{
			(*pnode)->cmd = malloc(sizeof(char *) * (i + 1));
			if (!(*pnode)->cmd)
				return (1);
			(*pnode)->cmd[i] = NULL;
			(*pnode) = (*pnode)->next;
			(*tnode) = (*tnode)->next;
			i = 0;
		}
		else if ((*tnode))
			(*tnode) = (*tnode)->next;
	}
	return (0);
}

int	get_cmds(t_lexer **thead, t_simple_cmd **phead)
{
	t_simple_cmd	*pnode;
	t_lexer			*tnode;
	int				i;

	pnode = *phead;
	tnode = *thead;
	i = 0;
	while (pnode)
	{
		if (get_cmds12(&tnode, &pnode, i))
			return (1);
		if (!tnode)
			break ;
	}
	get_cmds2(thead, phead);
	return (0);
}
