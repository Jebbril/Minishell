/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:37:37 by orakib            #+#    #+#             */
/*   Updated: 2023/04/10 14:23:32 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer	*ft_newtnode(char str, t_tokens token)
{
	t_lexer	*new;

	new = malloc(sizeof(t_lexer));
	if (!new)
		return (NULL);
	new->index = -1;
	new->token = token;
	new->str = str;
	new->prev = NULL;
	new->next = NULL;
}

void	ft_addtback(t_lexer **head, t_lexer *node)
{
	t_lexer	*tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		tmp = node;
		node->index = 0;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
	node->index = tmp->index + 1;
}
