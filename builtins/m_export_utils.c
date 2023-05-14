/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_export_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:32:34 by orakib            #+#    #+#             */
/*   Updated: 2023/05/14 18:00:27 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

int	exp_k(char *arg, t_env **envar)
{
	int		i;
	t_env	*vnode;

	i = -1;
	vnode = *envar;
	if (arg[i + 1] != '_' && !ft_isalpha(arg[i + 1]))
		return (printf("not a valid identifier\n"), EXIT_FAILURE);
	while (arg[++i])
		if (arg[i] != '_' && !ft_isalnum(arg[i]))
			return (printf("not a valid identifier\n"), EXIT_FAILURE);
	while (vnode)
	{
		if (ft_strncmp(arg, vnode->key, ft_strlen(vnode->key)) == 0
			&& ft_strncmp(arg, vnode->key, ft_strlen(arg)) == 0)
			return (EXIT_SUCCESS);
		vnode = vnode->next;
	}
	ft_addvback(envar, ft_newvnode(ft_substr(arg, 0, ft_strlen(arg)), NULL));
	return (EXIT_SUCCESS);
}

int	exp_knv(char *arg, t_env **envar)
{
	t_env	*vnode;
	int		i;
	int		j;
	char	*key;
	char	*value;

	i = 0;
	vnode = *envar;
	while (arg[i] && arg[i] != '=')
		i++;
	key = ft_substr(arg, 0, i);
	j = i;
	while (arg[j])
		j++;
	value = ft_substr(arg, i + 1, j - i);
	i = -1;
	if (key[i + 1] != '_' && !ft_isalpha(key[i + 1]))
		return (printf("not a valid identifier\n"), EXIT_FAILURE);
	while (key[++i])
		if (key[i] != '_' && !ft_isalnum(key[i]))
			return (printf("not a valid identifier\n"), EXIT_FAILURE);
	ft_addvback(envar, ft_newvnode(key, value));
	return (EXIT_SUCCESS);
}
