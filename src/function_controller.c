/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:00:20 by adubugra          #+#    #+#             */
/*   Updated: 2018/06/01 19:18:05 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"
#define PROCESS vm->champs[i].processes

/*
**	eliu: Changed run_processes(t_process *root, int i) to include vm.
** actually curr_op has an unknow ussage
*/

void	run_processes(t_vm *vm, t_process *root, int i)
{
	int j;

	if (!root)
		return ;
	j = 0;
	while (root)
	{
		root->contador_delete_me += 1;
//		printf(" RUN_PROCCESES_index ROOT: %d\n | number of time = |%d|\n", root->index, root->contador_delete_me);
		printf(" RUN_PROCCESES_index ROOT: %d\n | number of CYCLES = |%d|\n", root->index, vm->cycles);
		printf("CURRENT OP = %d\n", root->curr_op);

		j++;
		if (root->curr_op == 0)
		{
			fetch(root);
			//printf("champs %d, process %d fetched op %d\n", i + 1, j, root->curr_op);
		}
		if (root->cycle_counter == 0 && root->curr_op)
		{
			printf("champs %d prcss %d executing op %d:\n", i + 1, j, root->curr_op);
			execute(vm, root);
			fetch(root);
			root->cycle_counter--;
			printf("value is %d\n", root->arg.v[0]);
		}
		else if (root->cycle_counter > 0)
		{
			//printf("champs %d prcss %d has %d cycles before executing\n", i + 1, j, root->cycle_counter);
			root->cycle_counter--;
		}
		root = root->next;
	}
}

void	kill_processes(t_process **newhead)
{
	t_process	*tmp;

	tmp = NULL;
	if (!((*newhead)))
		return ;
	while((*newhead)->next)
	{
		if (!((*newhead)->next->process_alive)) // kill_process
		{
			tmp = (*newhead)->next;
			(*newhead)->next = (*newhead)->next->next;
			free(tmp);
		}
		else
			(*newhead) = (*newhead)->next;
	}
	if (!((*newhead)->process_alive))
	{
		tmp = *newhead;
		*newhead = (*newhead)->next;
		free(tmp);
	}
}

void	reset_values_processes(t_process **p)
{
	t_process *iter;

	if (!(*p))
		return ;
	iter = *p;
	while (iter)
	{
		iter->process_alive = 0;
		iter = iter->next;
	}
}

//#define INCREASE_NRB_CHECKS vm->nbr_checks += 1

/*
**	// if cycle_to_die == cycle_to_die_temp && checks == MAX_CHECKS
**	cycle_to_die -= DELTA_CYCLE;
**	if total_lives is at least NBR_LIVES, decrease cycle_to_die by CYCLE_DELTA
*/

void	handle_cycle_to_die(t_vm *vm)
{
	int			i;

	// check nbr_lives - count lives of every proccess
//	if ((vm->nbr_checks == MAX_CHECKS) && (vm->cycle_to_die == vm->cycle_to_die_last))
//	{
//		vm->cycle_to_die -= CYCLE_DELTA;
//	}
	if (vm->total_lives >= NBR_LIVE || (int)(vm->last_to_live) == 0 \
		|| vm->nbr_checks >= MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
//		if (vm->cycle_to_die <= 0)
//			continue ;
		vm->cycle_to_die_last = (unsigned int)vm->cycles + (unsigned int)vm->cycle_to_die;
		printf("MOTHERFUCKER WE ARE DECREMENTING CYCLE TO DIE, new value = %u\n", vm->cycle_to_die);
		printf("IF STATEMENT WE ARE PRINTING, new value = %u\n", vm->cycle_to_die_last);
		printf("Total number of lives before reseting = |%d|\n", vm->total_lives);
		vm->nbr_lives = 0;
		vm->nbr_checks = 0;
		vm->total_lives = 0;
	//	vm->cycle_to_die_last = vm->cycle_to_die;
		i = -1;
		while (++i < vm->players)
			kill_processes(&(PROCESS));
		i = -1;
		while (++i < vm->players)
		{
			vm->champs[i].lives_counted = 0;
			reset_values_processes(&(vm->champs[i].processes));
		}
	}
	else
	{
		vm->cycle_to_die_last = vm->cycles + vm->cycle_to_die;
		printf("ELSE STATEMENT new value = %u\n", vm->cycle_to_die_last);
	}

		i = -1;
		vm->total_lives = 0;
		while (++i < vm->players)
		{
			vm->champs[i].lives_counted = 0;
			reset_values_processes(&(vm->champs[i].processes));
		}
	printf("Total number of lives = |%d|\n", vm->total_lives);
	vm->nbr_checks += 1;
	printf("Total number of checks = |%d|\n", vm->nbr_checks);
}

int		operation_cycle_to_die(int cycles, int cytodie)
{
	if (cycles == cytodie)
		return (1);
	else
		return (0);
}



void	controller(t_vm *vm)
{
	int		i;

	while (1)
	{
		i = vm->players;
		while (0 <= --i)
			run_processes(vm, PROCESS, i);
		// handles correctly
//		if (((int)((*vm).cycles) % (int)((*vm).cycle_to_die)) == 0)
//		if ((((int)vm->cycles) % (int)(vm->cycle_to_die)) == 0)
//		if ((unsigned int)((*vm).cycles) == (unsigned int)((*vm).cycle_to_die_last))
		if (operation_cycle_to_die(vm->cycles, vm->cycle_to_die_last) == 1 || \
			vm->cycle_to_die <= 0)
		{
			handle_cycle_to_die(vm);
			if (procceses_alive(vm) == 1)
				break ;
		}
		if (vm->flags_args.dump == 1)
			if (vm->flags_args.nbrdump == vm->cycles)
				dump_memory_wrapper(*vm);
		vm->cycles++;
	}
}
