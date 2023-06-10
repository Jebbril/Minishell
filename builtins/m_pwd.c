/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orakib <orakib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:39:45 by orakib            #+#    #+#             */
/*   Updated: 2023/05/30 17:04:59 by orakib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/builtins.h"
#include <sys/param.h>

int	m_pwd(void)
{
	char	path[MAXPATHLEN];

	if (!getcwd(path, MAXPATHLEN))
		return (EXIT_FAILURE);
	printf("%s\n", path);
	return (EXIT_SUCCESS);
}
