/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:22:42 by orakib            #+#    #+#             */
/*   Updated: 2023/05/30 11:18:41 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtins.h"

int	unset_var(char *arg, t_env **envar)
{
	int		i;
	t_env	*vnode;

	i = -1;
	vnode = *envar;
	if (arg[i + 1] != '_' && !ft_isalpha(arg[i + 1]))
		return (write(2, "not a valid identifier\n", 24), EXIT_FAILURE);
	while (arg[++i])
		if (arg[i] != '_' && !ft_isalnum(arg[i]))
			return (write(2, "not a valid identifier\n", 24), EXIT_FAILURE);
	while (vnode)
	{
		if (ft_strncmp(arg, vnode->key, ft_strlen(vnode->key)) == 0
			&& ft_strncmp(arg, vnode->key, ft_strlen(arg)) == 0)
		{
			ft_delvone(envar, vnode);
			break ;
		}
		vnode = vnode->next;
	}
	return (EXIT_SUCCESS);
}

int	m_unset(char **args, t_env **envar)
{
	int		i;
	int		j;

	if (!args[1])
		return (EXIT_SUCCESS);
	i = 0;
	while (args[i])
	{
		if (unset_var(args[i], envar))
			j = 1;
		i++;
	}
	return (j);
}
