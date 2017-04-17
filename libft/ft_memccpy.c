/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:22:35 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/10 09:45:49 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*str_dest;
	char	*str_src;
	size_t	i;

	str_dest = (char*)dest;
	str_src = (char*)src;
	i = 0;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		if (str_src[i] == c)
			return ((char*)dest + ++i);
		i++;
	}
	return (0);
}
