/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_exitc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:50:25 by orakib            #+#    #+#             */
/*   Updated: 2023/05/29 17:34:00 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

static size_t	ft_size1(int n)
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

static char	*ft_fill1(char *str, long temp, size_t size)
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

char	*ft_itoa1(int n)
{
	long	temp;
	size_t	size;
	char	*str;

	size = ft_size1(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	temp = n;
	if (temp < 0)
	{
		temp *= -1;
		str[0] = '-';
	}
	str = ft_fill1(str, temp, size);
	return (str);
}

void	join_all2(char *before, char *after, char *value, t_lexer *tnode)
{
	char	*joined;

	joined = ft_strjoin(before, value);
	free(tnode->str);
	tnode->str = ft_strjoin(joined, after);
	free(joined);
}

void	expand_exitc(t_lexer *tnode, t_global *g_var, int i)
{
	char	*before;
	char	*after;
	char	*value;

	before = ft_substr(tnode->str, 0, i);
	after = ft_substr(tnode->str, i + 2, ft_strlen(tnode->str));
	value = ft_itoa1(g_var->exit_code);
	join_all2(before, after, value, tnode);
	free(value);
	free(before);
	free(after);
}
