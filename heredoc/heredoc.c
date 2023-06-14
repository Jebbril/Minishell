/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:49:37 by orakib            #+#    #+#             */
/*   Updated: 2023/06/14 12:52:42 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	open_heredoc2(char *filename, t_env **envar, t_lexer *tnode, int fd)
{
	char	*input;

	input = "";
	while (1)
	{
		input = readline("heredoc >");
		if (ft_strncmp(input, tnode->str, ft_strlen(input)) == 0
			&& ft_strncmp(input, tnode->str, ft_strlen(tnode->str)) == 0)
		{
			free(input);
			break ;
		}
		if (tnode->token == word)
			expand_heredoc(&input, envar);
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free(input);
	}
	free(tnode->str);
	tnode->str = filename;
	close(fd);
}

int	open_heredoc(t_lexer *tnode, int *i, t_env **envar)
{
	char	*filename;
	char	*number;
	int		fd;

	number = ft_itoa(*i);
	filename = ft_strjoin("/tmp/", number);
	if (access(filename, F_OK) == 0)
	{
		while (access(filename, F_OK) == 0)
		{
			(*i)++;
			free(filename);
			free(number);
			number = ft_itoa(*i);
			filename = ft_strjoin("/tmp/", number);
		}
	}
	fd = open(filename, O_RDWR | O_CREAT);
	if (fd == -1)
		return (free(filename), free(number), EXIT_FAILURE);
	open_heredoc2(filename, envar, tnode, fd);
	free(number);
	return (EXIT_SUCCESS);
}

int	nodes_loop(t_simple_cmd *pnode, int *i, t_env **envar)
{
	t_lexer	*tnode;

	tnode = *(pnode->redirections);
	while (tnode && g_var.status != ISCONTROLC)
	{
		if (tnode->token == here_doc)
		{
			tnode = tnode->next;
			if (tnode->token == w_space)
				tnode = tnode->next;
			if (open_heredoc(tnode, i, envar))
				return (EXIT_FAILURE);
		}
		tnode = tnode->next;
	}
	return (EXIT_SUCCESS);
}

int	get_heredocs(t_simple_cmd **cmds, t_env **envar)
{
	t_simple_cmd	*pnode;
	int				i;
	int				fd;

	if (!cmds)
		return (EXIT_SUCCESS);
	g_var.status = ISHEREDOC;
	fd = dup(0);
	pnode = *cmds;
	i = 1000000;
	while (pnode)
	{
		if (nodes_loop(pnode, &i, envar))
			return (EXIT_FAILURE);
		pnode = pnode->next;
	}
	dup2(fd, 0);
	close(fd);
	if (g_var.status == ISCONTROLC)
		return (EXIT_FAILURE);
	g_var.status = ISEXECUTING;
	return (EXIT_SUCCESS);
}
