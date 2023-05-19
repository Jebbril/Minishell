/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:49:37 by orakib            #+#    #+#             */
/*   Updated: 2023/05/19 18:07:05 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	open_heredoc2(char *filename, char *number, t_lexer *tnode, int fd)
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
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free(input);
	}
	free(number);
	free(tnode->str);
	tnode->str = filename;
	close(fd);
}

int	open_heredoc(t_lexer *tnode, int *i)
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
	open_heredoc2(filename, number, tnode, fd);
	return (EXIT_SUCCESS);
}

int	get_heredocs(t_simple_cmd **cmds)
{
	t_simple_cmd	*pnode;
	t_lexer			*tnode;
	int				i;

	pnode = *cmds;
	i = 1000000;
	while (pnode)
	{
		tnode = *(pnode->redirections);
		while (tnode)
		{
			if (tnode->token == here_doc)
			{
				tnode = tnode->next;
				if (tnode->token == w_space)
					tnode = tnode->next;
				if (open_heredoc(tnode, &i))
					return (EXIT_FAILURE);
			}
			tnode = tnode->next;
		}
		pnode = pnode->next;
	}
	return (EXIT_SUCCESS);
}
