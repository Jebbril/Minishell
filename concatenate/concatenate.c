/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:40:34 by orakib            #+#    #+#             */
/*   Updated: 2023/05/07 20:00:24 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	concatenate(t_lexer **thead, t_simple_cmd ** phead)
{
	t_simple_cmd	*pnode;
	t_lexer			*tnode;

	tnode = *thead;
	pnode = *phead;
	while (tnode)
	{
		if (tnode->token == word || tnode->token == sq_word
			|| tnode->token == dbq_word)
		{
			if (tnode->next)
			{
				if (tnode->next->token == word || tnode->next->token == sq_word
					|| tnode->next->token == dbq_word)
					tnode->str = ft_strjoin(tnode->str, tnode->next->str);
					ft_deltone(thead, tnode->next);
			}
			tnode = tnode->next;
		}
		if (tnode)
		tnode = tnode->next;
	}
}