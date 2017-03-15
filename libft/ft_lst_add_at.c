/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 12:04:33 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/14 12:48:36 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add_at(t_list **lst, t_list *new, int position)
{
	int		i;
	t_list	*list;

	if (!(*lst))
		*lst = new;
	else
	{
		i = 0;
		list = *lst;
		while(list->next && i < position)
		{
			list = list->next;
			i++;
		}
		list->next = new;
	}
}
