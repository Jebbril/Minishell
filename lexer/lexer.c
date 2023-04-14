/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:50:47 by orakib            #+#    #+#             */
/*   Updated: 2023/04/14 02:54:51 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lexer.h"

void	handle_quote(char *input, int *i, t_lexer **thead)
{
	t_lexer	*node;
	int		j;

	j = *i;
	if (input[j] == "\"")
	{
		while (input[j] != "\"")
		{
			if (!input[j])
			{
				ft_deltall(thead);
				exit(EXIT_FAILURE);
			}
			j++;
		}
	}
}

t_lexer	**tokenizer(char *input)
{
	t_lexer	**thead;
	int		i;

	if (!input || !input[0])
		return (NULL);
	thead = malloc(sizeof(t_lexer *));
	if (!thead)
		return (NULL);
	*thead = NULL;
	i = 0;
	while (input[i])
	{
		if (ft_isspace(input[i]))
			handle_space(input, &i, thead);
		else if (input[i] == '|' || input[i] == '>' || input[i] == '<')
			handle_sep(input, &i, thead);
		else if (input[i] == '\"' || input[i] == '\'')
			handle_quote(input, &i, thead);
		else
			handle_word(input, &i, thead);
	}
	return (thead);
}
