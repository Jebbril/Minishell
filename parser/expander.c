/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:25:03 by orakib            #+#    #+#             */
/*   Updated: 2023/05/29 17:28:38 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"
#include "../include/minishell.h"

void	join_all(char *before, char *after, char *value, t_lexer *tnode)
{
	char	*joined;

	joined = ft_strjoin(before, value);
	free(tnode->str);
	tnode->str = ft_strjoin(joined, after);
	free(joined);
}

void	keytovalue(t_lexer *tnode, t_env **envar, int i, int j)
{
	char	*before;
	char	*after;
	char	*var;
	char	*value;
	t_env	*vnode;

	before = ft_substr(tnode->str, 0, j);
	var = ft_substr(tnode->str, j + 1, i - j - 1);
	after = ft_substr(tnode->str, i, ft_strlen(tnode->str));
	value = "";
	vnode = *envar;
	while (vnode)
	{
		if (ft_strncmp(var, vnode->key, ft_strlen(vnode->key)) == 0
			&& ft_strncmp(var, vnode->key, ft_strlen(var)) == 0)
			value = vnode->value;
		vnode = vnode->next;
	}
	join_all(before, after, value, tnode);
	free(var);
	free(before);
	free(after);
}

int	ft_expand(t_lexer *tnode, t_env **envar, t_global *g_var)
{
	int	i;
	int	j;

	i = -1;
	while (tnode->str[++i])
	{
		if (tnode->str[i] == '$')
		{
			if (tnode->str[i + 1] == '?')
				expand_exitc(tnode, g_var, i);
			
			else if (tnode->str[i + 1] == '_' || ft_isalpha(tnode->str[i + 1]))
			{
				j = i++;
				while (tnode->str[i] == '_' || ft_isalnum(tnode->str[i]))
					i++;
				keytovalue(tnode, envar, i, j);
				i = j - 1;
			}
		}
	}
	return (0);
}

int	ft_expander2(t_simple_cmd *pnode, t_env **envar, t_global *g_var)
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
			if (ft_expand(tnode, envar, g_var))
				return (1);
		tnode = tnode->next;
	}
	return (0);
}

int	ft_expander(t_lexer **thead, t_simple_cmd **phead, t_env **envar
	, t_global *g_var)
{
	t_simple_cmd	*pnode;
	t_lexer			*tnode;

	tnode = *thead;
	pnode = *phead;
	while (tnode)
	{
		if (tnode->token == word || tnode->token == dbq_word)
			if (ft_expand(tnode, envar, g_var))
				return (1);
		tnode = tnode->next;
	}
	while (pnode)
	{
		if (ft_expander2(pnode, envar, g_var))
			return (1);
		pnode = pnode->next;
	}
	return (0);
}
