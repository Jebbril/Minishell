/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:23:13 by orakib            #+#    #+#             */
/*   Updated: 2023/06/11 17:20:54 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtins.h"

void	m_echo2(char **args, int *i, int *j)
{
	int	k;

	while (args[*i] && args[*i][0] && ft_strncmp(args[*i], "-n", 2) == 0)
	{
		k = 1;
		while (args[*i][++k])
			if (args[*i][k] != 'n')
				break ;
		if (args[*i][k] && args[*i][k] != 'n')
			break ;
		*j = 1;
		(*i)++;
	}
}

int	m_echo(char **args)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!args[i])
	{
		printf("\n");
		return (EXIT_SUCCESS);
	}
	m_echo2(args, &i, &j);
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	if (j == 0)
		printf("\n");
	return (EXIT_SUCCESS);
}
