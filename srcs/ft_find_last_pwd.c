/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_last_pwd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:57:00 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/14 16:57:20 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_find_last_pwd(char *pwd)
{
	if (!(ft_strchr(pwd, '/')))
		return (pwd);
	else
		pwd = ft_strchr(pwd, '/') + 1;
	return (ft_find_last_pwd(pwd));
}
