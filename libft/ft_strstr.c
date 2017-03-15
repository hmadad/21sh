/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:25:49 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/10 13:51:28 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *search)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strcmp(search, "") == 0)
		return ((char*)str);
	while (str[i])
	{
		if (str[i] == search[j])
		{
			while (search[j] && str[i + j] && search[j] == str[i + j])
				j++;
			if (search[j] == '\0')
				return ((char*)str + i);
			j = 0;
		}
		i++;
	}
	return (0);
}
