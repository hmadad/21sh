/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_commande.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:00:05 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/16 14:06:36 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_escape(t_shell **shell)
{
	t_shell	*s;

	s = *shell;
	ft_putstr("\n");
	ft_putstr(RED "-~[ Fermeture du Terminal ]~-\n" RESET);
	tcsetattr(0, TCSADRAIN, &(s->default_term));
	exit(0);
}

void	ft_update_history(t_shell **shell, t_list **commande)
{
	int			fd;
	t_shell		*s;
	char		*tmp;

	s = *shell;
	s->line = ft_ltos(commande);
	tmp = ft_strtrim(s->line);
	if (tmp && ft_strcmp(tmp, "") != 0)
	{
		if ((fd = open(".history", O_WRONLY | O_APPEND)) == -1)
			ft_putstr("Cannot open file\n");
		else
		{
			ft_putendl_fd(s->line, fd);
			close(fd);
		}
		ft_liste_push_front(&(s->history), ft_listenew(s->line));
		ft_strdel(&tmp);
	}
}

void	ft_read_commande(t_shell **shell)
{
	t_shell		*s;
	t_list		*chaine;
	char		buf[4];

	s = *shell;
	chaine = NULL;
	while (42)
	{
		ft_bzero(buf, 2);
		read(0, buf, 3);
		if (ft_strcmp(buf, "\n") == 0)
		{
			ft_update_history(&s, &chaine);
			//ft_exec_commande(shell);
			chaine = NULL;
			ft_putchar('\n');
			ft_prompt(s->env);
			ft_reset_position(shell);
		}
		else if (buf[0] == 27 && ft_strlen(buf) == 3)
			ft_history_key(shell, buf);
		else if (buf[0] == 27 && ft_strlen(buf) == 1)
			ft_escape(shell);
		else
		{
			ft_lst_push_back(&chaine, ft_lstnew(buf, 2));
			ft_putstr(buf);
			s->position += 1;
		}
	}
}
