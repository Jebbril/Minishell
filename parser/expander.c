/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:25:03 by orakib            #+#    #+#             */
/*   Updated: 2023/05/06 19:41:16 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

int	ft_expand(char *str, t_env **envar)
{
	int	i;
	int	j;
	char	*before;
	char	*after;

	i = 0;
	j = 0;
	(void)after;
	(void)envar;
	if (ft_strchr(str, '$'))
	{
		while (str[i] && str[i] != '$')
		{
			i++;
		}
		before = ft_substr(str, 0, i);
	}
	return (0);
}

int	ft_expander(t_lexer **thead, t_simple_cmd **phead, t_env **envar)
{
	t_simple_cmd	*pnode;
	t_lexer			*tnode;

	tnode = *thead;
	pnode = *phead;
	while (tnode)
	{
		if (tnode->token == word || tnode->token == dbq_word)
			if (ft_expand(tnode->str, envar))
				return (1);
		tnode = tnode->next;
	}
	return (0);
}
