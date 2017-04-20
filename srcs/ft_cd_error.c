/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 12:13:43 by hmadad            #+#    #+#             */
/*   Updated: 2017/04/19 12:40:36 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_cd_errors(char *newpath, char **home)
{
	struct stat	stats;

	lstat(newpath, &stats);
	if (access(newpath, F_OK) == 0)
	{
		if (!(S_ISREG(stats.st_mode)))
			ft_putendl("cd : permission denied");
		else
			ft_putendl("cd : not a directory");
	}
	else
		ft_putendl("cd: no such file or directory");
	*home = NULL;
}
