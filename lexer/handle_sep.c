/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:33:31 by orakib            #+#    #+#             */
/*   Updated: 2023/05/19 15:50:05 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

t_lexer	*handle_sep2(char *input, int *i)
{
	if (input[*i + 1] == '>')
	{
		(*i)++;
		return (ft_newtnode(NULL, rd_output_apnd));
	}
	else
		return (ft_newtnode(NULL, rd_output));
}

int	handle_sep(char *input, int *i, t_lexer **thead)
{
	t_lexer	*node;

	node = NULL;
	if (input[*i] == '|')
		node = ft_newtnode(NULL, is_pipe);
	else if (input[*i] == '<')
	{
		if (input[*i + 1] == '<')
		{
			node = ft_newtnode(NULL, here_doc);
			(*i)++;
		}
		else
			node = ft_newtnode(NULL, rd_input);
	}
	else if (input[*i] == '>')
		node = handle_sep2(input, i);
	if (!node)
		return (1);
	ft_addtback(thead, node);
	(*i)++;
	return (0);
}
