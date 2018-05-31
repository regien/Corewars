/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:00:20 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/30 21:59:36 by gmalpart         ###   ########.fr       */
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
		printf(" RUN_PROCCESES_index ROOT: %d\n | number of time = |%d|\n", root->index, root->contador_delete_me);
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
	if (!((*newhead)->live))
	{
		tmp = *newhead;
		*newhead = (*newhead)->next;
		free(tmp);
	}
}

#define INCREASE_NRB_CHECKS vm->nbr_checks += 1

void	handle_cycle_to_die(t_vm *vm)
{
	int			i;

	// check nbr_lives - count lives of every proccess
	if (vm->nbr_lives >= NBR_LIVE || \
		vm->nbr_checks == MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->nbr_lives = 0;
		vm->nbr_checks = -1;
	}
	i = 0;
	while (i < vm->players)
	{
		kill_processes(&(PROCESS));
		i++;
	}
	INCREASE_NRB_CHECKS;
}

void	controller(t_vm *vm)
{
	int		i;

	while (1)
	{
		i = vm->players;
		while (0 <= --i)
			run_processes(vm, PROCESS, i);
		vm->cycles++;
		// handles correctly
		if (((int)((*vm).cycles) % (int)((*vm).cycle_to_die)) == 0)
		{
			handle_cycle_to_die(vm);
			if (procceses_alive(vm) == 1)
				break ;
		}
		if (vm->flags_args.dump == 1)
			if (vm->flags_args.nbrdump == vm->cycles)
				dump_memory_wrapper(*vm);
	}
}
