/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:39:45 by orakib            #+#    #+#             */
/*   Updated: 2023/06/14 21:34:20 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtins.h"
#include <sys/param.h>

int	m_pwd(t_env **envar)
{
	char	str[MAXPATHLEN];

	(void)envar;
	if (!getcwd(str, MAXPATHLEN))
	{
		perror("");
		return (1);
	}
	printf("%s\n", str);
	return (EXIT_SUCCESS);
}
