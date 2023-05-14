/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:03:09 by orakib            #+#    #+#             */
/*   Updated: 2023/05/12 18:10:42 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

int	m_env(t_env **envar)
{
	t_env	*vnode;

	vnode = *envar;
	while (vnode)
	{
		if (vnode->value)
			printf("%s=%s\n", vnode->key, vnode->value);
		vnode = vnode->next;
	}
	return (EXIT_SUCCESS);
}
