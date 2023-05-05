/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:13:44 by orakib            #+#    #+#             */
/*   Updated: 2023/05/05 17:34:05 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/envir.h"
#include "../include/lexer.h"

t_env	**get_envar(char **env)
{
	t_env	**envar;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	envar = malloc(sizeof(t_env *));
	if (!envar)
		return (NULL);
	*envar = NULL;
	while (env[++i])
	{
		while (env[i][j] != '=')
			j++;
		k = j + 1;
		while (env[i][k])
			k++;
		ft_addvback(envar, ft_newvnode(ft_substr(env[i], 0, j),
				ft_substr(env[i], j + 1, k)));
		j = 0;
		k = 0;
	}
	return (envar);
}
