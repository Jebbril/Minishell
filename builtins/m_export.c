/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:19:38 by orakib            #+#    #+#             */
/*   Updated: 2023/05/11 18:53:33 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

void	exp_print(t_env **envar)
{
	t_env	*vnode;
	t_env	*tmp;

	vnode = *envar;
	while (vnode)
	{
		tmp = *envar;
		while (tmp)
		{
			if (ft_strncmp(tmp->key, ))
			tmp = tmp->next
		}
		vnode = vnode->next;
	}
}

int	m_export(char **args, t_env **envar)
{
	t_env	*vnode;

	vnode = *envar;
	if (!args[1])
	{
		exp_print(envar);
		return (EXIT_SUCCESS);
	}	
}
