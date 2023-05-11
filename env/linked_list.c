/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:04:33 by orakib            #+#    #+#             */
/*   Updated: 2023/05/11 18:51:52 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/envir.h"

t_env	*ft_newvnode(char *key, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->key = key;
	node->value = value;
	node->printed = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_addvback(t_env **vhead, t_env *vnode)
{
	t_env	*tmp;

	tmp = *vhead;
	if (tmp == NULL)
	{
		*vhead = vnode;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = vnode;
	vnode->prev = tmp;
}

void	ft_delvall(t_env **vhead)
{
	t_env	*tmp;
	t_env	*node;

	tmp = *vhead;
	while (tmp)
	{
		if (tmp->key)
			free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		node = tmp;
		tmp = tmp->next;
		free(node);
	}
	free(vhead);
}
