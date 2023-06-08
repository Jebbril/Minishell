/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:14:26 by edraidry          #+#    #+#             */
/*   Updated: 2023/06/08 17:04:20 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strnstr( const char *s1, const char *chr, size_t k)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !k)
		return (NULL);
	if (*chr == '\0')
		return ((char *)(s1));
	while ((s1[i] != '\0') && i < k)
	{
		j = 0;
		while (s1[i + j] == chr[j] && (i + j) < k)
		{
			j++;
			if ((int)j == ft_strlen((char *)chr))
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
