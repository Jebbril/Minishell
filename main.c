/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:27:49 by orakib            #+#    #+#             */
/*   Updated: 2023/05/04 16:57:16 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_simple_cmd	**commands;
	t_lexer			**tokens;
	char			*str;

	(void)env;
	(void)ac;
	(void)av;
	while (1)
	{
		str = readline("Minishell >");
		add_history(str);
		tokens = tokenizer(str);
		commands = parser(tokens);
		if (tokens)
			ft_deltall(tokens);
		if (commands)
			ft_delpall(commands);
		free(str);
	}
}