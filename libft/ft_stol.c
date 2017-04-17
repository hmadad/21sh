/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 11:51:10 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/14 11:58:27 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_stol(char *str)
{
	int		i;
	char	*s;
	t_list	*list;

	i = 0;
	s = ft_strdup(" ");
	while (str[i])
	{
		s[0] = str[i];
		ft_lst_push_back(&list, ft_lstnew(str, 2));
	}
	ft_strdel(&s);
	return (list);
}
