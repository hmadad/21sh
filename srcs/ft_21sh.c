/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:43:27 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/15 13:37:36 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_21sh(char ***env)
{
	t_shell		*shell;
	char		*line;

	if (!(shell = (t_shell *)malloc(sizeof(t_shell))))
		return (0);
	shell->env = *env;
	shell->history = ft_init_term(&shell);
	ft_prompt(*env);
	if ((line = tgetstr("sc", NULL)) == NULL)
		ft_putstr("Cannot save the cursor position\n");
	else
		tputs(line, 0, ft_putc);
	ft_read_commande(&shell);
	return (1);
}
