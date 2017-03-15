/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:17:00 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/23 14:56:13 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str_dest;
	char	*str_src;
	size_t	i;

	i = 0;
	str_dest = (char*)dest;
	str_src = (char*)src;
	if (src < dest)
	{
		while (n)
		{
			n--;
			str_dest[n] = str_src[n];
		}
	}
	else
	{
		while (i < n)
		{
			str_dest[i] = str_src[i];
			i++;
		}
	}
	return (dest);
}
