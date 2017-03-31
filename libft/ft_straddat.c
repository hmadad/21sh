/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:41:04 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/29 11:39:46 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddat(char *str, char c, size_t position)
{
	size_t		i;
	size_t		j;
	char	*new;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
		return (0);
	new[ft_strlen(str) + 1] = '\0';
	if (position >= ft_strlen(str))
		return (new = ft_free_join(str, ft_ctostr(c), 'B'));
	while (str[j])
	{
		if (i == position)
			new[i] = c;
		else
		{
			new[i] = str[j];
			j++;
		}
		i++;
	}
	return (new);
}
