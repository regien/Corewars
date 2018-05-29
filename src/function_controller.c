/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:00:20 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/29 04:36:15 by gmalpart         ###   ########.fr       */
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

/*
//t_process	*kill_processes(t_process *head)
void	kill_processes(t_process **head)
{
	t_process	*newhead;
	t_process	*iter;
	t_process	*temp_erase;

	temp_erase = NULL;
	newhead = head;
	iter = newhead;
	while(iter)
	{
		if (!iter->live) // kill_process
		{
			temp_erase = iter;
			iter = iter->next;
			free(temp_erase);
		}
		else
			iter = iter->next;
	}
//	return (newhead);
}
*/

void	kill_processes(t_process **newhead)
{
//	t_process	*newhead;
	t_process	*tmp;

//	newhead = *head;
	tmp = NULL;
	while((*newhead)->next)
	{
		if (!((*newhead)->next->live)) // kill_process
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
		free(*newhead);
		*newhead = NULL;
	}
//	return (newhead);
}


/*
** seem that's the function is currently not in use
**		NOT FULLY FUNCTIONAL
** Fix this first
*/

#define INCREASE_NRB_CHECKS vm->nbr_checks += 1

void	handle_cycle_to_die(t_vm *vm)
{
	int			i;
//	t_process	*buffer;

	if (vm->nbr_lives >= NBR_LIVE || \
		vm->nbr_checks == MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		vm->nbr_lives = 0;
		vm->nbr_checks = 0;
	}
	i = 0;
	vm->champs[0].processes->live = 1;
	while (i < vm->players)
	{
//		buffer = PROCESS;
//		while (buffer)
//		{
//			if (!buffer->live)
//				//kill_process(buffer); // not working
//			buffer = buffer->next;
//		}
//		PROCESS = kill_processes(PROCESS);
		kill_processes(&(PROCESS));
		i++;
	}
	INCREASE_NRB_CHECKS;
}

void	controller(t_vm *vm)
{
	int		i;

	i = -1; // proccess are already initialized when the champion is being checked
//	while (++i < vm->players)
//		add_process(&(vm->champs[i]), vm->champs[i].processes->index + 16);
	while (1)
	{
		i = 0;
		while (i < vm->players)
		{
			run_processes(vm, PROCESS, i);
			i++;
		}
		vm->cycles++;
		// handles correctly
		if (((int)((*vm).cycles) % (int)((*vm).cycle_to_die)) == 0)
		{
			handle_cycle_to_die(vm);
			if (procceses_alive(vm) == 1)
				break ;
		}
//		ft_printf("curr cycle: %d\n", vm->cycles);
//		if (vm->cycles == 10)
//			break ;
	}
}
