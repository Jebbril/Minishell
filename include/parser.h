/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 08:50:24 by orakib            #+#    #+#             */
/*   Updated: 2023/04/27 19:17:24 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

# include "lexer.h"

typedef struct s_simple_cmd
{
	int					index;
	char				**cmd;
	char				*builtin;
	t_lexer				**redirections;
	char				*heredoc_file;
	struct s_simple_cmd	*prev;
	struct s_simple_cmd	*next;
}	t_simple_cmd;

t_simple_cmd	**parser(t_lexer **thead);
int				pipe_errors(t_lexer *tnode);
int				rd_errors(t_lexer *tnode);
int				start_end_errors(t_lexer *tnode);

#endif