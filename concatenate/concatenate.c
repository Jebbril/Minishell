/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:32:52 by orakib            #+#    #+#             */
/*   Updated: 2023/05/17 16:56:39 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	split_word(t_lexer *tnode)
{
	int		i;
	char	*tmp1;
	char	*tmp2;
	t_lexer	*new;
	t_lexer	*space;

	i = 0;
	while (tnode->str[i] != ' ')
		i++;
	tmp1 = tnode->str;
	tnode->str = ft_substr(tnode->str, 0, i);
	tmp2 = ft_substr(tmp1, i + 1, ft_strlen(tmp1) - i);
	new = ft_newtnode(tmp2, word);
	space = ft_newtnode(NULL, w_space);
	space->next = new;
	new->prev = space;
	new->next = tnode->next;
	if (tnode->next)
		tnode->next->prev = new;
	tnode->next = space;
	space->prev = tnode;
	free(tmp1);
}

void	join_nodes(t_lexer **thead, t_lexer *tnode)
{
	char	*tmp;

	while (tnode && (tnode->token == word
			|| tnode->token == sq_word || tnode->token == dbq_word))
	{
		if (tnode->next)
		{
			if (tnode->next->token == word
				|| tnode->next->token == sq_word
				|| tnode->next->token == dbq_word)
			{
				if (tnode->next->token == sq_word
					|| tnode->next->token == dbq_word)
					tnode->token = sq_word;
				tmp = tnode->str;
				tnode->str = ft_strjoin(tnode->str, tnode->next->str);
				ft_deltone(thead, tnode->next);
				free(tmp);
			}
		}
		tnode = tnode->next;
	}
}

void	concat_rd(t_simple_cmd *pnode)
{
	t_lexer	*tnode;

	while (pnode)
	{
		tnode = *(pnode->redirections);
		while (tnode)
		{
			if (tnode->token == word || tnode->token == sq_word
				|| tnode->token == dbq_word)
				join_nodes(pnode->redirections, tnode);
			tnode = tnode->next;
		}
		pnode = pnode->next;
	}
}

int	concatenate(t_lexer **thead, t_simple_cmd **phead)
{
	t_simple_cmd	*pnode;
	t_lexer			*tnode;

	if (!phead)
		return (0);
	tnode = *thead;
	pnode = *phead;
	while (tnode)
	{
		if (tnode->token == word)
			if (ft_strchr(tnode->str, ' '))
				split_word(tnode);
		tnode = tnode->next;
	}
	tnode = *thead;
	while (tnode)
	{
		if (tnode->token == word || tnode->token == sq_word
			|| tnode->token == dbq_word)
			join_nodes(thead, tnode);
		tnode = tnode->next;
	}
	concat_rd(pnode);
	get_cmds(thead, phead);
	return (0);
}
