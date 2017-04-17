/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 11:33:56 by hmadad            #+#    #+#             */
/*   Updated: 2017/04/17 11:48:17 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_strtrimb(char *str)
{
	char	*new;
	int		i;

	if (!str)
		return (0);
	new = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] != '\b')
			new = ft_free_join(new, ft_strsub(str, i, 1), 'B');
		i++;
	}
	new[i] = '\0';
	return (new);
}
