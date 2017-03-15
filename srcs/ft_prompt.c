/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:17:06 by hmadad            #+#    #+#             */
/*   Updated: 2017/02/20 09:25:59 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_prompt(char **g_env)
{
	char	*tmp;

	ft_putstr(GRN "-> " CYN);
	if ((tmp = ft_getenv(g_env, "PWD")))
		ft_putstr(ft_find_last_pwd(tmp));
	ft_putstr("> " RESET);
}
