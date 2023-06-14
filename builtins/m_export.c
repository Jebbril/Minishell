/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:19:38 by orakib            #+#    #+#             */
/*   Updated: 2023/06/14 17:56:47 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtins.h"

void	exp_print(t_env **envar)
{
	t_env	*vnode;

	vnode = *envar;
	while (vnode)
	{
		if (vnode->value)
			printf("declare -x %s=\"%s\"\n", vnode->key, vnode->value);
		else
			printf("declare -x %s\n", vnode->key);
		vnode = vnode->next;
	}
}

int	exp_add(char **args, t_env **envar)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (args[++j])
	{
		if (ft_strchr(args[j], '='))
		{
			if (exp_knv(args[j], envar))
				i = 1;
		}
		else
		{
			if (exp_k(args[j], envar))
				i = 1;
		}
	}
	return (i);
}

int	m_export(char **args, t_env **envar)
{
	if (!args[1])
	{
		exp_print(envar);
		return (EXIT_SUCCESS);
	}
	else
	{
		if (exp_add(args, envar))
			return (EXIT_FAILURE);
	}
	return (0);
}
