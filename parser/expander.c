/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:25:03 by orakib            #+#    #+#             */
/*   Updated: 2023/05/07 18:32:34 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

void	get_join2(char *before, char *after, t_env *vnode, t_lexer *tnode)
{
	char	*joined;
	char	*tmp;

	if (vnode->value)
		tmp = ft_strjoin(before, vnode->value);
	else
		tmp = ft_strjoin(before, "");
	joined = ft_strjoin(tmp, after);
	free(tmp);
	free(tnode->str);
	tnode->str = joined;
	if (tnode->str[0] == '\'')
	{
		tnode->str = ft_strjoin(joined, "'");
		free(joined);
	}
	free(before);
	free(after);
}

void	get_join(t_lexer *tnode, char *before, char *after, t_env **envar)
{
	int		i;
	int		j;
	char	*var;
	t_env	*vnode;

	i = 0;
	vnode = *envar;
	while (tnode->str[i] && tnode->str[i] != '$')
		i++;
	i++;
	j = i;
	while (tnode->str[j] && tnode->str[j] != ' ' && tnode->str[j] != '\'')
		j++;
	var = ft_substr(tnode->str, i, j - i);
	while (vnode)
	{
		if (ft_strncmp(var, vnode->key, ft_strlen(vnode->key)) == 0
			&& ft_strncmp(var, vnode->key, ft_strlen(var)) == 0)
			get_join2(before, after, vnode, tnode);
		vnode = vnode->next;
	}
	free(var);
}

int	ft_expand(t_lexer *tnode, t_env **envar)
{
	int		i;
	int		j;
	char	*before;
	char	*after;

	i = 0;
	j = 0;
	before = "";
	after = "";
	if (ft_strchr(tnode->str, '$'))
	{
		while (tnode->str[i] && tnode->str[i] != '$')
			i++;
		if (tnode->str[i + 1] == 0 || tnode->str[i + 1] == ' ')
			return (0);
		before = ft_substr(tnode->str, 0, i);
		while (tnode->str[i] && tnode->str[i] != ' ')
			i++;
		j = i;
		while (tnode->str[i])
			i++;
		after = ft_substr(tnode->str, j, i);
		get_join(tnode, before, after, envar);
	}
	return (0);
}

int	ft_expander2(t_simple_cmd *pnode, t_env **envar)
{
	t_lexer			*tnode;

	tnode = *pnode->redirections;
	while (tnode)
	{
		if (tnode->token == here_doc)
		{
			tnode = tnode->next;
			if (tnode->token == w_space)
				tnode = tnode->next;
			while (tnode && (tnode->token == word
					|| tnode->token == dbq_word))
				tnode = tnode->next;
		}
		if (!tnode)
			break ;
		if (tnode->token == word || tnode->token == dbq_word)
			if (ft_expand(tnode, envar))
				return (1);
		tnode = tnode->next;
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
			if (ft_expand(tnode, envar))
				return (1);
		tnode = tnode->next;
	}
	while (pnode)
	{
		if (ft_expander2(pnode, envar))
			return (1);
		pnode = pnode->next;
	}
	return (0);
}
