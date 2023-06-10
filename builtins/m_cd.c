/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:02:46 by orakib            #+#    #+#             */
/*   Updated: 2023/05/27 20:48:48 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtins.h"
#include <dirent.h>

int	m_cd(char **args, t_env **envar)
{
	t_env	*vnode;

	vnode = *(envar);
	if (!args[1])
	{
		while (vnode)
		{
			if (ft_strncmp("HOME", vnode->key, 4) == 0
				&& ft_strncmp("HOME", vnode->key, ft_strlen(vnode->key)) == 0)
				break ;
			vnode = vnode->next;
		}
		chdir(vnode->value);
		return (EXIT_SUCCESS);
	}
	if (!args[1][0])
		return (EXIT_SUCCESS);
	if (chdir(args[1]) != 0)
	{
		perror("Minishell: cd");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
