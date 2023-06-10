/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:48:50 by orakib            #+#    #+#             */
/*   Updated: 2023/05/19 15:50:18 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parser.h"

t_lexer	*ft_cpynode(t_lexer *tnode)
{
	t_lexer	*ret;
	char	*str;

	str = NULL;
	if (tnode->str)
	{
		str = malloc(sizeof(char) * (ft_strlen(tnode->str) + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, tnode->str, ft_strlen(tnode->str) + 1);
	}
	ret = ft_newtnode(str, tnode->token);
	if (!ret)
		return (NULL);
	return (ret);
}

int	get_rds3(t_lexer **tnode, t_simple_cmd **pnode, t_lexer **thead)
{
	t_lexer	*ttmp;

	ft_addtback((*pnode)->redirections, ft_cpynode((*tnode)));
	ttmp = *tnode;
	*tnode = (*tnode)->next;
	ft_deltone(thead, ttmp);
	if ((*tnode)->token == w_space)
	{
		ft_addtback((*pnode)->redirections, ft_cpynode((*tnode)));
		ttmp = *tnode;
		*tnode = (*tnode)->next;
		ft_deltone(thead, ttmp);
	}
	while ((*tnode)->token == word || (*tnode)->token == sq_word
		|| (*tnode)->token == dbq_word)
	{
		ft_addtback((*pnode)->redirections, ft_cpynode((*tnode)));
		ttmp = *tnode;
		*tnode = (*tnode)->next;
		ft_deltone(thead, ttmp);
		if (!(*tnode))
			break ;
	}
	return (0);
}

int	get_rds2(t_lexer *tnode, t_simple_cmd *pnode, t_lexer **thead)
{
	while (tnode)
	{
		if (tnode->token == rd_output_apnd || tnode->token == here_doc
			|| tnode->token == rd_input || tnode->token == rd_output)
		{
			get_rds3(&tnode, &pnode, thead);
		}
		if (!tnode)
			break ;
		if (tnode->token == is_pipe)
			pnode = pnode->next;
		if (tnode->token != rd_output_apnd && tnode->token != here_doc
			&& tnode->token != rd_input && tnode->token != rd_output)
		tnode = tnode->next;
	}
	return (0);
}

int	get_rds(t_lexer **thead, t_simple_cmd **phead)
{
	t_simple_cmd	*pnode;
	t_lexer			*tnode;

	tnode = *thead;
	pnode = *phead;
	while (pnode)
	{
		pnode->redirections = malloc(sizeof(t_lexer *));
		if (!pnode->redirections)
			return (1);
		*(pnode->redirections) = NULL;
		pnode = pnode->next;
	}
	pnode = *phead;
	get_rds2(tnode, pnode, thead);
	return (0);
}
