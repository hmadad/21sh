/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_commande.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:00:05 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/15 14:12:54 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_update_history(t_shell **shell, t_list **commande)
{
	int			fd;
	char		*str_commande;
	t_shell		*s;

	s = *shell;
	s->line = ft_ltos(commande);
	if (ft_strcmp(ft_strtrim(s->line), "") != 0)
	{
		if ((fd = open(".history", O_WRONLY | O_APPEND)) == -1)
			ft_putstr("Cannot open file\n");
		else
		{
			ft_putendl_fd(s->line, fd);
			close(fd);
		}
		ft_liste_push_front(&(s->history), ft_listenew(str_commande));
		ft_putchar('\n');
		ft_putstr("?>");
		if ((str_commande = tgetstr("sc", NULL)) == NULL)
			ft_putstr("bug save cursor position\n");
		else
			tputs(str_commande, 0, ft_putc);
	}
}

void	ft_read_commande(t_shell **shell)
{
	t_shell		*s;
	t_history	*h;
	t_list		*chaine;
	char		buf[4];
	char		*string;
	int			fd;
	char		*line;

	s = *shell;
	h = s->history;
	chaine = NULL;
	while (42)
	{
		ft_bzero(buf, 2);
		read(0, buf, 3);
		if (ft_strcmp(buf, "\n") == 0)
		{
			ft_update_history(&s, &chaine);
		}
		else if (buf[0] == 27 && ft_strlen(buf) == 3)
		{
			if (h)
			{
				if (buf[2] == 'A')
				{
					if ((line = tgetstr("rc", NULL)) == NULL)
						ft_putstr("bug restor cursor position\n");
					else
						tputs(line, 0, ft_putc);
					if ((line = tgetstr("cd", NULL)) == NULL)
						ft_putstr("bug cd UP\n");
					else
						tputs(line, 0, ft_putc);
					ft_putstr("?>");
					ft_putstr(h->content);
					if (h->next)
						h = h->next;
				}
				if (buf[2] == 'B')
				{
					if ((line = tgetstr("rc", NULL)) == NULL)
						ft_putstr("bug restor cursor position\n");
					else
						tputs(line, 0, ft_putc);
					if ((line = tgetstr("cd", NULL)) == NULL)
						ft_putstr("bug cd down\n");
					else
						tputs(line, 0, ft_putc);
					ft_putstr("?>");
					ft_putstr(h->content);
					if (h->previous)
						h = h->previous;
				}
			}
		}
		else if (buf[0] == 27 && ft_strlen(buf) == 1)
		{
			ft_putstr("\n");
			ft_putstr(RED "-~[ Fermeture du Terminal ]~-\n" RESET);
			tcsetattr(0, TCSADRAIN, &(s->default_term));
			exit(0);
		}
		else
		{
			ft_lst_push_back(&chaine, ft_lstnew(buf, 2));
			ft_putstr(buf);
		}
	}
}
