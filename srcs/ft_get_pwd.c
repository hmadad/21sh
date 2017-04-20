/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 10:28:46 by hmadad            #+#    #+#             */
/*   Updated: 2017/04/19 12:54:38 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*get_pwd(void)
{
	char	*new;
	int		len;

	len = 1;
	if (!(new = (char *)malloc(sizeof(char) * (len))))
		return (0);
	while (!(new = getcwd(new, len)))
	{
		len += 1;
		free(new);
		if (!(new = (char *)malloc(sizeof(char) * (len))))
			return (0);
	}
	return (new);
}
