/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spcsep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:28:37 by orakib            #+#    #+#             */
/*   Updated: 2023/04/14 02:33:50 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

void	handle_space(char *input, int *i, t_lexer **thead)
{
	t_lexer	*node;

	while (ft_isspace(input[*i]))
	{
		(*i)++;
	}
	node = ft_newtnode(NULL, w_space);
	if (!node)
	{
		ft_deltall(thead);
		exit(EXIT_FAILURE);
	}
	ft_addtback(thead, node);
}

void	handle_sep2(char *input, int *i, t_lexer **thead, t_lexer *node)
{
	if (input[*i] == '>')
	{
		if (input[*i + 1] == '>')
		{
			node = ft_newtnode(NULL, rd_output_apnd);
			(*i)++;
		}
		else
			node = ft_newtnode(NULL, rd_output);
	}
	if (!node)
	{
		ft_deltall(thead);
		exit(EXIT_FAILURE);
	}
	(*i)++;
}

void	handle_sep(char *input, int *i, t_lexer **thead)
{
	t_lexer	*node;

	if (input[*i] == '|')
		node = ft_newtnode(NULL, pipe);
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
	handle_sep2(input, i, thead, node);
}
