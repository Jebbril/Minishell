/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:27:01 by orakib            #+#    #+#             */
/*   Updated: 2023/04/27 19:37:36 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	start_end_errors(t_lexer *tnode)
{
	t_lexer	*tmp;

	tmp = tnode;
	if (tmp->token == rd_input || tmp->token == rd_output || tmp->token == pipe
		|| tmp->token == here_doc || tmp->token == rd_output_apnd)
	{
		if (tmp->next)
			if (tmp->next->token == w_space)
				tmp = tmp->next;
		if (tmp->next == NULL)
			return (1);
	}
	tmp = tnode;
	if (tmp->token == pipe)
	{
		if (tmp->prev)
			if (tmp->prev->token == w_space)
				tmp = tmp->prev;
		if (tmp->prev == NULL)
			return (1);
	}
	return (0);
}

int	pipe_errors(t_lexer *tnode)
{
	t_lexer	*tmp;

	tmp = tnode;
	if (tmp->prev->token == w_space)
		tmp = tmp->prev;
	if (tmp->prev->token == word || tmp->prev->token == dbq_word
		|| tmp->prev->token == sq_word)
		return (0);
	tmp = tnode;
	if (tmp->next->token == w_space)
		tmp = tmp->next;
	if (tmp->next->token == word || tmp->next->token == dbq_word
		|| tmp->next->token == sq_word || tmp->next->token == rd_input
		|| tmp->next->token == rd_output || tmp->next->token == here_doc
		|| tmp->next->token == rd_output_apnd)
		return (0);
	printf("Syntax Error\n");
	return (1);
}

int	rd_errors(t_lexer *tnode)
{
	t_lexer	*tmp;

	tmp = tnode;
	if (tmp->next->token == w_space)
		tmp = tmp->next;
	if (tmp->next->token == word || tmp->next->token == dbq_word
		|| tmp->next->token == sq_word)
		return (0);
	printf("Syntax Error\n");
	return (1);
}
