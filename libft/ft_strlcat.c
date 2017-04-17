/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:09:37 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/14 14:52:54 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] && i < n)
		i++;
	while (src[j] && (i + j + 1) < n)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i != n)
		dest[i + j] = '\0';
	return (ft_strlen(src) + i);
}
