/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:23:13 by orakib            #+#    #+#             */
/*   Updated: 2023/05/30 17:04:59 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtins.h"

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
	if (args[i][0] && ft_strncmp(args[i], "-n", ft_strlen(args[i])) == 0)
	{
		j = 1;
		i++;
	}
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
