/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:04:32 by orakib            #+#    #+#             */
/*   Updated: 2023/04/26 17:26:11 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

t_simple_cmd	*ft_newpnode(void)
{
	t_simple_cmd	*new;

	new = malloc(sizeof(t_simple_cmd));
	if (!new)
		return (NULL);
	new->index = -1;
	new->cmd = NULL;
	new->builtin = NULL;
	new->redirections = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_addpback(t_simple_cmd **head, t_simple_cmd *node)
{
	t_simple_cmd	*tmp;

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

void	ft_delpall(t_simple_cmd **phead)
{
	t_simple_cmd	*tmp;
	t_simple_cmd	*node;

	tmp = *phead;
	while (tmp)
	{
		node = tmp;
		tmp = tmp->next;
		free(node);
	}
	free(phead);
}
