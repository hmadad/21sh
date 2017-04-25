/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:35:54 by hmadad            #+#    #+#             */
/*   Updated: 2017/04/25 14:59:25 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_command_not_found(char *str, char **opt)
{
	if (!str)
	{
		ft_putstr(opt[0]);
		ft_putstr(": command not found\n");
	}
	return (1);
}

int		ft_full_path(t_shell **shell)
{
	pid_t		father;
	struct stat	st;
	t_shell *s;

	s = *shell;
	if (access((s->opt)[0], F_OK) == 0)
	{
		if (lstat((s->opt)[0], &st) == 0)
		{
			if (S_ISREG(st.st_mode))
			{
				if (st.st_mode & S_IRUSR)
				{
					father = fork();
					if (father > 0)
						wait(0);
					if (father == 0)
						execve((s->opt)[0], s->opt, s->env);
					return (1);
				}
			}
		}
	}
	return (0);
}

char	*ft_command_process(t_shell **shell, char *commande)
{
	char	*tmp;
	pid_t	father;
	int		i;
	t_shell *s;

	s = *shell;
	if (!(s->path))
		return (0);
	i = 0;
	while (s->path && (s->path)[i])
	{
		tmp = ft_free_join(ft_strjoin((s->path)[i], "/"), commande, 'L');
		if (access(tmp, F_OK) == 0)
		{
			father = fork();
			if (father > 0)
				wait(0);
			if (father == 0)
				execve(tmp, s->opt, s->env);
			ft_strdel(&tmp);
			break ;
		}
		ft_strdel(&tmp);
		i++;
	}
	return ((s->path)[i]);
}

void	ft_check_commande(t_shell **shell, char *commande)
{
	char	*str;
	t_shell *s;

	s = *shell;
	if (ft_full_path(shell) == 1)
		return ;
	else
		str = ft_command_process(shell, commande);
	if (!(s->path))
		ft_command_not_found(NULL, s->opt);
	else
		ft_command_not_found(str, s->opt);
	return ;
}
