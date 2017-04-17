/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 08:35:55 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/10 09:33:45 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str_dest;
	char	*str_src;

	str_dest = (char*)dest;
	str_src = (char*)src;
	while (n != 0)
	{
		n--;
		str_dest[n] = str_src[n];
	}
	return (dest);
}
