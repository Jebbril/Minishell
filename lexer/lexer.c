/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:50:47 by orakib            #+#    #+#             */
/*   Updated: 2023/03/17 15:58:52 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer	**tokenizer(char *input)
{
	t_lexer	**thead;
	int		i;

	thead = malloc(sizeof(t_lexer *));
	if (!thead)
		return (NULL);
	if (!input || !input[0])
		return (NULL);
	
}