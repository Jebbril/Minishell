/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 09:01:14 by orakib            #+#    #+#             */
/*   Updated: 2023/04/27 18:47:28 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	syntax_errors(t_lexer **thead, t_simple_cmd **phead)
{
	t_lexer	*tnode;

	tnode = *thead;
	(void)phead;
	while (tnode)
	{
		if (tnode->token == pipe || tnode->token == rd_input
			|| tnode->token == rd_output
			|| tnode->token == rd_output_apnd || tnode->token == here_doc)
			if (start_end_errors(tnode))
				return (1);
		if (tnode->token == pipe)
			if (pipe_errors(tnode))
				return (1);
		if (tnode->token == rd_input || tnode->token == rd_output
			|| tnode->token == rd_output_apnd || tnode->token == here_doc)
			if (rd_errors(tnode))
				return (1);
		tnode = tnode->next;
	}
	return (0);
}

t_simple_cmd	**parser(t_lexer **thead)
{
	t_simple_cmd	**phead;

	if (!thead)
	{
		printf("error during tokenization\n");
		return (NULL);
	}
	phead = malloc(sizeof(t_simple_cmd *));
	if (!phead)
		return (NULL);
	*phead = NULL;
	if (*thead == NULL)
	{
		// free(thead);
		return (phead);
	}
	if (syntax_errors(thead, phead))
		return (phead);
	return (phead);
}
