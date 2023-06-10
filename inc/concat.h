/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:55:05 by orakib            #+#    #+#             */
/*   Updated: 2023/06/06 19:00:23 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONCAT_H

# define CONCAT_H

# include "parser.h"

int	concatenate(t_lexer **thead, t_simple_cmd **phead);
int	get_cmds(t_lexer **thead, t_simple_cmd **phead);
int	ft_expand(t_lexer *tnode, t_env **envar);

#endif