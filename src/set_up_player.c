/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 18:55:45 by gmalpart          #+#    #+#             */
/*   Updated: 2018/05/24 21:34:25 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		get_nbr_player(int ac, int *i, char **av, t_vm *vm)
{
	int		nbr_player;

	nbr_player = 0;
	*i = *i + 1;
	if (*i < ac && av[*i])
	{
		check_for_chars(av[*i]);
		nbr_player = ft_atoi(av[*i]); // you got the number here
		if (nbr_player < 0)
			nbr_player = nbr_player * -1;
		if (nbr_player <= 0 || nbr_player > MAX_PLAYERS)
			general_exit(g_ivlid_nbr, -1);
		set_up_player_nbr(nbr_player, vm, &(vm->champs[vm->players]));
		if (*i + 1 < ac && check_name_champ(av[*i + 1]) == 0)
			general_exit(g_ivlid_chmp, -1);
		*i += 1;
		set_up_player_fd(ac, av, i, vm);
	}
	else
		general_exit(g_ivlid_nbr, -1);
}

/*
**	Initiliazes the number of the player and also initializes the counter
**	of lives to 0
*/

void		set_up_player_nbr(int nbr_player, t_vm *vm, t_champ *champs)
{
	if (!champs)
		champs = malloc(sizeof(champs));
	vm->players = vm->players + 1; // count of the players
	if (vm->players > MAX_PLAYERS)
		general_exit(g_ivlid_nbrpls, -1);
	if (nbr_player == 0)
		nbr_player = vm->players;
	champs->plyr_nbr = nbr_player;
	champs->lives_counted = 0;
}

void		set_up_player_fd(int ac, char **av, int *i, t_vm *vm)
{
	if (*i >= ac)
		general_exit(g_ivlid_nbr, -1);
	vm->champs[vm->players - 1].fd = open(av[*i], O_RDONLY);
	vm->champs[vm->players - 1].size = 0;
//	vm->champs[vm->players - 1].processes = 0;
	if (vm->champs[vm->players - 1].fd < 0)
		general_exit(g_ivlid_chmp, -1);
}

void		wrap_set_up_player(int ac, int *i, char **av, t_vm *vm)
{
	set_up_player_nbr(0, vm, &(vm->champs[vm->players]));
	set_up_player_fd(ac, av, i, vm);
}
