/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:52:17 by orakib            #+#    #+#             */
/*   Updated: 2023/05/04 14:21:00 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

int	handle_dbquote(char *input, int *i, t_lexer **thead)
{
	t_lexer	*node;
	int		j;
	char	*str;

	j = *i;
	if (input[j] == '\"')
	{
		j++;
		while (input[j] != '\"')
		{
			if (!(input[j]))
				return (1);
			j++;
		}
		j++;
	}
	str = ft_substr(input, (*i), (j - (*i)));
	if (!str)
		return (1);
	node = ft_newtnode(str, dbq_word);
	if (!node)
		return (1);
	(*i) += j - (*i);
	ft_addtback(thead, node);
	return (0);
}

int	handle_squote(char *input, int *i, t_lexer **thead)
{
	t_lexer	*node;
	int		j;
	char	*str;

	j = *i;
	if (input[j] == '\'')
	{
		j++;
		while (input[j] != '\'')
		{
			if (!(input[j]))
				return (1);
			j++;
		}
		j++;
	}
	str = ft_substr(input, (*i), (j - (*i)));
	if (!str)
		return (1);
	node = ft_newtnode(str, sq_word);
	if (!node)
		return (1);
	(*i) += j - (*i);
	ft_addtback(thead, node);
	return (0);
}

int	handle_quote(char *input, int *i, t_lexer **thead)
{
	if (input[*i] == '\"')
	{
		if (handle_dbquote(input, i, thead))
			return (1);
	}
	else if (input[*i] == '\'')
	{
		if (handle_squote(input, i, thead))
			return (1);
	}
	return (0);
}
