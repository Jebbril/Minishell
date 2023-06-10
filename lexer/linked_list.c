/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:37:37 by orakib            #+#    #+#             */
/*   Updated: 2023/05/05 17:43:05 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lexer.h"

t_lexer	*ft_newtnode(char *str, t_tokens token)
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
	return (new);
}

void	ft_addtback(t_lexer **head, t_lexer *node)
{
	t_lexer	*tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		*head = node;
		node->index = 0;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
	node->index = tmp->index + 1;
}

t_lexer	*ft_lasttnode(t_lexer **thead)
{
	t_lexer	*node;

	node = *thead;
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	ft_deltone(t_lexer **thead, t_lexer *tnode)
{
	if (!tnode)
		return ;
	if (!tnode->next && !tnode->prev)
		*thead = NULL;
	else
	{
		if (!tnode->prev)
			*thead = tnode->next;
		if (tnode->next)
			tnode->next->prev = tnode->prev;
		if (tnode->prev)
			tnode->prev->next = tnode->next;
	}
	if (tnode->str)
		free(tnode->str);
	free(tnode);
}

void	ft_deltall(t_lexer **thead)
{
	t_lexer	*tmp;
	t_lexer	*node;

	if (thead == (t_lexer **)(1))
		return ;
	tmp = *thead;
	while (tmp)
	{
		if (tmp->str)
			free(tmp->str);
		node = tmp;
		tmp = tmp->next;
		free(node);
	}
	free(thead);
}
