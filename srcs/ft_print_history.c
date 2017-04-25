/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:00:30 by hmadad            #+#    #+#             */
/*   Updated: 2017/04/25 15:05:13 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_print_history()
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	fd = open(".history", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_putnbr(i);
		ft_putchar(' ');
		ft_putendl(line);
		i++;
	}
}
