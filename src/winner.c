/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 01:05:21 by gmalpart          #+#    #+#             */
/*   Updated: 2018/05/29 02:55:48 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	CHECK - champion for this value
		so wen you 
	int					lives_counted;

EZEKIEL:
	value on the vm
		-last_one_to_called_live is the person who is gonna win the game
		- it always update for the latest player (players[i]) to called a function
		live before the game ends (*when there's no processes)
*/

int		procceses_alive(t_vm *vm)
{
	int	i;
	int	players_alive;
	t_process *temp;

	players_alive = 0;
	i = -1;
	vm->champs[0].processes->live = 1;
	while (++i < vm->players)
	{
		temp = vm->champs[i].processes;
		if (temp)
			players_alive++;
	}
	printf("pendejada PLAYERS_ALIVE = |%d|\n", players_alive);
	if (players_alive == 1)
		return (1);
	if (players_alive == 0) // in this case, 1 player wins
		return (1);
	else
		return (0);
}

/*
int		procceses_alive(t_vm *vm)
{
	int	i;
	int	players_alive;

	players_alive = 0;
	i = -1;
	vm->champs[0].processes->live = 1;
	while (++i < vm->players)
		if ((vm->champs[i].processes != 0))
			players_alive++;
	printf("pendejada PLAYERS_ALIVE = |%d|\n", players_alive);
	if (players_alive == 1)
		return (1);
	if (players_alive == 0) // in this case, 1 player wins
		return (1);
	else
		return (0);
}
*/

int		solid_winner(t_process *proceses)
{
	t_process *iter;

	iter = proceses;
	if (!proceses)
		return (0);
	while (iter)
	{
		if (proceses->live == 1)
			return (1);
		iter = iter->next;
	}
	return (0);
}

void	display_information_winner(t_champ *champ)
{
	ft_printf("The winner is Player %d\n\tName: %s\n", \
			champ->plyr_nbr, \
			champ->name);
	ft_printf("\tComment: %s\n", champ->comment);
	ft_printf("\tSize: %u\n", champ->size);
}

// check for last_one-to_called_alive

void	declare_winner(t_vm *vm)
{
	int		i;
	char	win_for_pc_alive;

	win_for_pc_alive = 0;
	i = -1;
	while (++i < vm->players)
	{
		if (solid_winner(vm->champs[i].processes) == 1)
		{
			display_information_winner(&(vm->champs[i]));
			win_for_pc_alive = 1;
		}
	}
	// if no proccess is alive -> champ[0] always win
	if (win_for_pc_alive == 0)
		display_information_winner(&(vm->champs[0]));
}
