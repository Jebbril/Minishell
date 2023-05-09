/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:55:05 by orakib            #+#    #+#             */
/*   Updated: 2023/05/09 17:03:15 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONCAT_H

# define CONCAT_H

# include "parser.h"

int	concatenate(t_lexer **thead, t_simple_cmd **phead);
int	get_cmds(t_lexer **thead, t_simple_cmd **phead);

#endif