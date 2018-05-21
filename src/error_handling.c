/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:11:28 by gmalpart          #+#    #+#             */
/*   Updated: 2018/05/21 03:19:23 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


char	g_ivlid_dump[] = "Invalid usage of -dump, see -h or --help\n";
char	g_ivlid_nbr[] = "Invalid usage of -n, see -h or --help\n";
char	g_ivlid_chmp[] = "Invalid champion file, see -h or --help\n";
char	g_ivlid_nbrpls[] = "Invalid Numbers of players, see -h or --help\n";
char	g_ivlid_dupl[] = "Duplicated number in players\n";
char	g_usage[] =
"\nExtras\n\t-v\tvisual flag\n"
"\t-n\tChoose the number of the player\n"
"\t-dump\tChoose the number of cycles to dump\n"
"\t\t* print the address of the map on the screen 😫\n";

void		general_exit(char *str, int code)
{
	ft_putstr_fd(str, 2);
	exit(code);
}

void	check_duplicate_players(t_vm *vm)
{
	int		i;
	int		e;

	if (vm->players <= 1)
		general_exit(g_ivlid_nbrpls, -1);
	i = -1;
	while (++i < vm->players)
	{
		e = -1;
		while (++e < vm->players)
		{
			if ((int)(vm->champs[i].plyr_nbr) == \
				(int)(vm->champs[e].plyr_nbr) && \
				i != e)
				general_exit(g_ivlid_dupl, -1);
		}
	}
}

int		simple_usage(int code, char *str)
{
	ft_putstr("usage:");
	ft_putstr(str);
	ft_putstr(" champ1.cor champ2.cor ...\n");
	ft_putstr(g_usage);
	exit(code);
	return (0);
}

int		check_name_champ(char *str)
{
	if (ft_strlen(str) < 5)
		return (0);
	if ((ft_strequ((ft_strstr(str, ".cor")), ".cor")) == 0)
		return (0);
	return (1);
}

#define LOWERCASE str[i] >= 'a' && str[i] <= 'z'
#define UPPERCASE str[i] >= 'A' && str[i] <= 'Z'
#define CARACTS str[i] == '-'

int		check_for_chars(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (( LOWERCASE ) || ( UPPERCASE ) || ( CARACTS ))
			general_exit("invalid dump variable\n", -1);
	return (1);
}
