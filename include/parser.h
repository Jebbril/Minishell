/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 08:50:24 by orakib            #+#    #+#             */
/*   Updated: 2023/04/26 11:30:25 by orakib           ###   ########.fr       */
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
	struct s_simple_cmd	*prev;
	struct s_simple_cmd	*next;
}	t_simple_cmd;

t_simple_cmd	**parser(t_lexer **thead);

#endif