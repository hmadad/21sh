/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:17:06 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/16 11:25:42 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_prompt(char **env)
{
	char	*tmp;

	ft_putstr(GRN "-> " CYN);
	if ((tmp = ft_getenv(env, "PWD")))
		ft_putstr(ft_find_last_pwd(tmp));
	ft_putstr("> " RESET);
	if ((tmp = tgetstr("sc", NULL)) == NULL)
		ft_putstr("Cannot save the cursor position\n");
	else
		tputs(tmp, 0, ft_putc);
}
