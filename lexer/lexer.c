/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:50:47 by orakib            #+#    #+#             */
/*   Updated: 2023/04/28 17:50:40 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lexer.h"

int	handle_loop(char *input, int *i, t_lexer **thead)
{
	while (input[*i])
	{
		if (ft_isspace(input[*i]))
		{
			if (handle_space(input, i, thead))
				return (1);
		}
		else if (input[*i] == '|' || input[*i] == '>' || input[*i] == '<')
		{
			if (handle_sep(input, i, thead))
				return (1);
		}
		else if (input[*i] == '\"' || input[*i] == '\'')
		{
			if (handle_quote(input, i, thead))
				return (1);
		}
		else
		{
			if (handle_word(input, i, thead))
				return (1);
		}
	}
	return (0);
}

t_lexer	**tokenizer(char *input)
{
	t_lexer	**thead;
	int		i;

	if (!input || !input[0])
		return ((t_lexer **)(1));
	thead = malloc(sizeof(t_lexer *));
	if (!thead)
	{
		return (NULL);
	}
	*thead = NULL;
	i = 0;
	if (handle_loop(input, &i, thead))
	{
		ft_deltall(thead);
		return (NULL);
	}
	return (thead);
}
