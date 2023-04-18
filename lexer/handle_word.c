/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:23:33 by orakib            #+#    #+#             */
/*   Updated: 2023/04/18 13:54:36 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

int	handle_word(char *input, int *i, t_lexer **thead)
{
	t_lexer	*node;
	int		j;
	char	*str;

	j = *i;
	while (input[j] && input[j] != '|' && input[j] != '<'
		&& input[j] != '>' && input[j] != '\'' && input[j] != '\"'
		&& !ft_isspace(input[j]))
		j++;
	str = ft_substr(input, (*i), (j - (*i)));
	if (!str)
		return (1);
	node = ft_newtnode(str, word);
	if (!node)
		return (1);
	*i += j - (*i);
	ft_addtback(thead, node);
	return (0);
}
