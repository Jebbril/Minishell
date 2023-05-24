/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:31:06 by orakib            #+#    #+#             */
/*   Updated: 2023/05/24 09:55:21 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	join_all1(char *before, char *after, char *value, char **input)
{
	char	*joined;

	joined = ft_strjoin(before, value);
	free((*input));
	(*input) = ft_strjoin(joined, after);
	free(joined);
}

void	keytovalue1(char **input, t_env **envar, int i, int j)
{
	char	*before;
	char	*after;
	char	*var;
	char	*value;
	t_env	*vnode;

	before = ft_substr((*input), 0, j);
	var = ft_substr((*input), j + 1, i - j - 1);
	after = ft_substr((*input), i, ft_strlen((*input)));
	value = "";
	vnode = *envar;
	while (vnode)
	{
		if (ft_strncmp(var, vnode->key, ft_strlen(vnode->key)) == 0
			&& ft_strncmp(var, vnode->key, ft_strlen(var)) == 0)
			value = vnode->value;
		vnode = vnode->next;
	}
	join_all1(before, after, value, input);
	free(var);
	free(before);
	free(after);
}

void	expand_heredoc(char **input, t_env **envar)
{
	int	i;
	int	j;

	i = -1;
	while ((*input)[++i])
	{
		if ((*input)[i] == '$')
		{
			if ((*input)[i + 1] == '_' || ft_isalpha((*input)[i + 1]))
			{
				j = i++;
				while ((*input)[i] == '_' || ft_isalnum((*input)[i]))
					i++;
				keytovalue1(input, envar, i, j);
				i = j - 1;
			}
		}
	}
}
