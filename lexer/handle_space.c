/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 02:28:37 by orakib            #+#    #+#             */
/*   Updated: 2023/04/18 11:44:27 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lexer.h"

int	handle_space(char *input, int *i, t_lexer **thead)
{
	t_lexer	*node;

	while (ft_isspace(input[*i]))
		(*i)++;
	node = ft_newtnode(NULL, w_space);
	if (!node)
		return (1);
	ft_addtback(thead, node);
	return (0);
}
