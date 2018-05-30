/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 01:05:21 by gmalpart          #+#    #+#             */
/*   Updated: 2018/05/30 03:14:22 by gmalpart         ###   ########.fr       */
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

// SETTING THE WINNER INCORRECTLY
/*
int		procceses_alive(t_vm *vm)
{
	int	i;
	int	players_alive;
	t_process *temp;

	players_alive = 0;
	i = -1;
	while (++i < vm->players)
	{
		temp = (vm->champs[i].processes);
		if (temp)
		{
			printf("PENDEJADA TEMP->PROCCESES->ALIVE = |%d|\n", \
				temp->live);
			players_alive++;
		}
	}
	printf("pendejada PLAYERS_ALIVE = |%d|\n", players_alive);
	if (players_alive == 1)
		return (1);
	if (players_alive == 0) // in this case, 1 player wins
		return (1);
	else
		return (0);
}
*/

int		procceses_alive(t_vm *vm)
{
	int	i;
	int	process_alive;
	t_process *temp;

	process_alive = 0;
	i = -1;
	while (++i < vm->players)
	{
		temp = (vm->champs[i].processes);
		if (temp)
		{
			printf("PENDEJADA TEMP->PROCCESES->ALIVE = |%d|\n", \
				temp->live);
			process_alive++;
		}
	}
	printf("pendejada PROCESSES_ALIVE _ PENDEJADA NBR = |%d|\n", process_alive);
	if (process_alive == 0) // GAME SHOULD END HERE
		return (1);
	return (0);
}

void	display_information_winner(t_champ *champ)
{
	ft_printf("The winner is Player %d\n\tName: %s\n", \
			champ->plyr_nbr, \
			champ->name);
	ft_printf("\tComment: %s\n", champ->comment);
	ft_printf("\tSize: %u\n", champ->size);
	exit(0);
}

void	declare_winner(t_vm *vm)
{
	int		i;

	i = -1;
	vm->last_to_live *= -1;
	printf("vm->last_to_live = |%d|\n", vm->last_to_live);
	while (++i < vm->players)
		if (vm->last_to_live == vm->champs[i].plyr_nbr)
			display_information_winner(&(vm->champs[vm->last_to_live]));
	display_information_winner(&(vm->champs[0]));
}
