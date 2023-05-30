/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:58:13 by orakib            #+#    #+#             */
/*   Updated: 2023/05/30 17:03:44 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	get_redirection(t_simple_cmd *command)
{
	t_lexer	*tnode;

	tnode = *(command->redirections);
	while (tnode)
	{
		if (tnode->token == here_doc || tnode->token == rd_input)
		{
			tnode = tnode->next;
			if (tnode->token == w_space)
				tnode = tnode->next;
			command->infd = open(tnode->str, O_RDONLY);
			if (command->infd == -1)
			{
				perror("Minishell : ");
				return (EXIT_FAILURE);
			}
		}
		if (tnode->token == rd_output)
		{
			tnode = tnode->next;
			if (tnode->token == w_space)
				tnode = tnode->next;
			command->outfd = open(tnode->str, O_WRONLY | O_CREAT, 0666);
			if (command->outfd == -1)
			{
				perror("Minishell");
				return (EXIT_FAILURE);
			}
		}
		if (tnode->token == rd_output_apnd)
		{
			tnode = tnode->next;
			if (tnode->token == w_space)
				tnode = tnode->next;
			command->outfd = open(tnode->str, O_WRONLY | O_APPEND | O_CREAT, 0666);
			if (command->outfd == -1)
			{
				perror("Minishell");
				return (EXIT_FAILURE);
			}
		}
		tnode = tnode->next;
	}
	return (EXIT_SUCCESS);
}
