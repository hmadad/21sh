/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:55:23 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/13 15:29:03 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(*new))) && lst)
	{
		new = f(lst);
		if (lst->next)
			new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	return (NULL);
}
