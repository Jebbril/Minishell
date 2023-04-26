/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 09:01:14 by orakib            #+#    #+#             */
/*   Updated: 2023/04/26 16:38:28 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

t_simple_cmd	**parser(t_lexer **thead)
{
	t_simple_cmd	**phead;

	if (!thead)
	{
		printf("error during tokenization\n");
		return (NULL);
	}
	phead = malloc(sizeof(t_simple_cmd *));
	if (!phead)
		return (NULL);
	*phead = NULL;
	if (*thead == NULL)
	{
		free(thead);
		return (phead);
	}
	return (phead);
}
