/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:58:33 by edraidry          #+#    #+#             */
/*   Updated: 2023/06/08 17:02:28 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	**error(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			count++ ;
		if ((s[i] == c && s[i + 1] != c) && (s[i] == c && s[i + 1] != '\0'))
			count++ ;
		i++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*calloc_words(const char *s1, int len)
{
	char	*copy;
	int		j;

	j = 0;
	copy = (char *) malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (j < len)
	{
		copy[j] = s1[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**spl;
	int		j;
	int		i ;
	int		wl;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	spl = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!spl)
		return (NULL);
	while (i < count_words(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		wl = word_len(s + j, c);
		spl[i] = calloc_words(s + j, wl);
		if (!spl[i])
			return (error(spl));
		j += wl;
		i++;
	}
	spl[i] = 0;
	return (spl);
}
