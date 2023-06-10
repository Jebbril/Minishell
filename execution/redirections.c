/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:58:13 by orakib            #+#    #+#             */
/*   Updated: 2023/06/06 18:57:27 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	get_input(t_simple_cmd *command, t_lexer **tnode)
{
	if ((*tnode)->token == here_doc || (*tnode)->token == rd_input)
	{
		if (command->infd != 0)
			close(command->infd);
		(*tnode) = (*tnode)->next;
		if ((*tnode)->token == w_space)
			(*tnode) = (*tnode)->next;
		command->infd = open((*tnode)->str, O_RDONLY);
		if (command->infd == -1)
		{
			command->infd = 0;
			perror("Minishell");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	get_output(t_simple_cmd *command, t_lexer **tnode)
{
	if ((*tnode)->token == rd_output)
	{
		if (command->outfd != 1)
			close(command->outfd);
		(*tnode) = (*tnode)->next;
		if ((*tnode)->token == w_space)
			(*tnode) = (*tnode)->next;
		command->outfd = open((*tnode)->str,
				O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (command->outfd == -1)
		{
			command->outfd = 1;
			perror("Minishell");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	get_output_appnd(t_simple_cmd *command, t_lexer **tnode)
{
	if ((*tnode)->token == rd_output_apnd)
	{
		if (command->outfd != 1)
			close(command->outfd);
		(*tnode) = (*tnode)->next;
		if ((*tnode)->token == w_space)
			(*tnode) = (*tnode)->next;
		command->outfd = open((*tnode)->str,
				O_WRONLY | O_APPEND | O_CREAT, 0666);
		if (command->outfd == -1)
		{
			command->outfd = 1;
			perror("Minishell");
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	get_redirection(t_simple_cmd *command)
{
	t_lexer	*tnode;

	tnode = *(command->redirections);
	while (tnode)
	{
		if (get_input(command, &tnode))
		{
			g_var.exit_code = 1;
			return (EXIT_FAILURE);
		}
		if (get_output(command, &tnode))
		{
			g_var.exit_code = 1;
			return (EXIT_FAILURE);
		}
		if (get_output_appnd(command, &tnode))
		{
			g_var.exit_code = 1;
			return (EXIT_FAILURE);
		}
		tnode = tnode->next;
	}
	return (EXIT_SUCCESS);
}
