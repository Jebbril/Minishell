/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:47:21 by orakib            #+#    #+#             */
/*   Updated: 2023/05/30 11:18:57 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

static int	ft_spc(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			i++;
		else
			break ;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	unsigned long	res;
	int				sign;
	int				i;

	res = 0;
	sign = 1;
	i = ft_spc(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (res > 9223372036854775807 && sign == -1)
				return (0);
			if (res > 9223372036854775807 && sign == 1)
				return (-1);
			res = res * 10 + str[i++] - 48;
		}
	}
	return (res * sign);
}

int	m_exit2(char **args, t_global *g_var)
{
	int	i;

	i = -1;
	if ((args[1][0] == '-' || args[1][0] == '+')
		&& args[1][1])
		i++;
	while (args[1][++i])
	{
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			write(2, "numeric argument required\n", 27);
			g_var->exit_code = 255;
			exit(255);
		}
	}
	if (args[2])
	{
		write(2, "too many arguments\n", 20);
		g_var->exit_code = 1;
		return (1);
	}
	return (0);
}

int	m_exit(char **args, t_global *g_var)
{
	if (!args[1])
	{
		g_var->exit_code = 0;
		exit(0);
	}
	if (!args[1][0])
	{
		write(2, "numeric argument required\n", 27);
		g_var->exit_code = 255;
		exit(255);
	}
	if (m_exit2(args, g_var))
		return (1);
	g_var->exit_code = ft_atoi(args[1]) % 256;
	if (g_var->exit_code < 0)
		g_var->exit_code += 256;
	exit(ft_atoi(args[1]));
	return (0);
}
