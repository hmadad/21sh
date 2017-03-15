/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:47:50 by hmadad            #+#    #+#             */
/*   Updated: 2017/03/14 17:13:46 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_find_term_db(char *term_name)
{
	int		result;

	result = tgetent(0, term_name);
	if (result == 0 || result == -1)
	{
		if (result == 0)
		{
			ft_putstr(term_name);
			ft_putstr(" not found in the termcap DB\n");
		}
		else
			ft_putstr("Could not access to the termcap DB\n");
		return (-1);
	}
	ft_putstr(term_name);
	ft_putstr(" Successfully found in termcap DB\n");
	return (0);
}

int		ft_modif_term(t_shell **shell)
{
	struct termios	term;
	struct termios	default_term;
	t_shell			*s;

	s = *shell;
	if (tcgetattr(0, &term) == -1)
	{
		ft_putstr("Error cannot fill up the term struct\n");
		return (-1);
	}
	ft_putstr("Term struct successfully filled up\n");
	s->default_term = term;
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
	{
		ft_putstr("Cannot apply the change on the term struct\n");
		return (-1);
	}
	ft_putstr("Change successfully apply\n");
	return (0);
}

t_history	*ft_load_history()
{
	int			fd;
	char		*line;
	t_history	*history;

	if ((fd = open(".history", O_RDONLY)) == -1)
	{
		ft_putstr("Cannot open history file\n");
		return (0);
	}
	while (get_next_line(fd, &line) != 0)
	{
		ft_liste_push_front(&history, ft_listenew(line));
		ft_strdel(&line);
	}
	close(fd);
	return (history);
}

t_history	*ft_init_term(t_shell **shell)
{
	char	*term_name;

	term_name = getenv("TERM");
	if (term_name == 0 || ft_find_term_db(term_name) == -1)
	{
		if (term_name == 0)
			ft_putstr("TERM is undefined in env\n");
		exit(EXIT_FAILURE);
	}
	if (ft_modif_term(shell) == -1)
		exit(EXIT_FAILURE);
	return (ft_load_history());
}
