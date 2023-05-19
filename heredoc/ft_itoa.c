/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:30:42 by orakib            #+#    #+#             */
/*   Updated: 2023/05/19 17:24:53 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static size_t	ft_size(int n)
{
	size_t	size;
	long	temp;

	temp = n;
	size = 0;
	if (temp < 0)
	{
		temp *= -1;
		size++;
	}
	while (temp >= 10)
	{
		temp = temp / 10;
		size++;
	}
	size++;
	return (size);
}

static char	*ft_fill(char *str, long temp, size_t size)
{
	size_t	i;

	i = size - 1;
	str[size] = 0;
	while (i >= 0)
	{
		if (temp >= 10)
		{
			str[i] = '0' + temp % 10;
			temp = temp / 10;
		}
		else
		{
			str[i] = '0' + temp;
			break ;
		}
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long	temp;
	size_t	size;
	char	*str;

	size = ft_size(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	temp = n;
	if (temp < 0)
	{
		temp *= -1;
		str[0] = '-';
	}
	str = ft_fill(str, temp, size);
	return (str);
}
