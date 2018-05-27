/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:00:20 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/26 23:19:30 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"
#define PROCESS vm->champs[i].processes

/*
**	eliu: Changed run_processes(t_process *root, int i) to include vm.
*/

/*
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
*/


/*
** seem that's the function is currently not in use
*/

/*
void	handle_cycle_to_die(t_vm *vm)
{
	int			i;
	t_process	*buffer;

	vm->cycle_to_die -= CYCLE_DELTA;
	i = 0;
	while (i < vm->players)
	{
		buffer = PROCESS;
		while (buffer)
		{
			if (!buffer->live)
				kill_process(buffer);
			buffer = buffer->next;
		}
		i++;
	}
}
*/


t_process	*init_process(t_vm *vm)
{
	t_process *new;

	new = ft_memalloc(sizeof(*new));
	new->player_number = i * -1;

}

void	add_processes(t_vm *vm)
{
	if (vm->processes == NULL)
	{
		init_process(t_vm *vm);
	}
}


void	link_processes(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < players)
	{
		vm->processes = add_process(vm, i);
	}
}

void	controller(t_vm *vm)
{
	int		i;

	i = 0;
//	while (
	vm->processes = link_processes(vm);

//	vm->process = init_me_motherfucker 
//	add_process(&(vm->champs[i]), vm->champs[i].processes->index + 16);
	while (1)
	{
		i = 0;
		while (i < vm->players)
		{
//			run_processes(vm, PROCESS, i);
			i++;
		}
		vm->cycles++;
	//	if (vm->cycles % vm->cycle_to_die == 0)
	//		handle_cycle_to_die(vm);
		ft_printf("curr cycle: %d\n", vm->cycles);
		if (vm->cycles == 10)
			break ;
	}
}
