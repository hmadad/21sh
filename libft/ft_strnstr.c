/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:56:48 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/13 17:34:43 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *search, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strcmp(search, "") == 0)
		return ((char*)str);
	while (str[i] && i < n)
	{
		if (str[i] == search[j])
		{
			while (str[i + j] == search[j] && search[j] && (i + j) < n)
				j++;
			if (search[j] == '\0')
				return ((char*)str + i);
			j = 0;
		}
		i++;
	}
	return (0);
}
