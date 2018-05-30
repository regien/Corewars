/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:00:20 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/30 03:26:01 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
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

/*
**	Might be a problem with 3 players? Double check to see that index
**	is set properly. All comments are vars that might not be necessary.
*/


/*
t_proces	*kill_processes(t_process *current)
{
	t_process *head;
	t_process *prev;

	head = current;
	prev = current;
	while (current)
	{
		if (current->process_live == 0)
		{
			if (current == head)
			{
				head = current->next;
			}
			now_we_are_free(current->process);
			prev->next = current->next;
		}
		prev = current;
		current = current->next;
	}
	// some print statement to make sure relinking is done properly.
	// temporary process number flag to keep track of processes.
}
*/

// gmalpart changes
void		kill_processes(t_process **current)
{
	// some print statement to make sure relinking is done properly.
	// temporary process number flag to keep track of processes.

	t_process	*list;

	if (!current || !(*current))
		return ;
	if ((*current)->process_alive == 0)
	{
		list = *current;
		*current = (*current)->next;
		free(list);
		kill_processes(current);
	}
	else
		kill_processes(&(*current)->next);
	return ;
}

//int			*init_regs(int regs[REG_NUMBER + 1], int player_number)
void			init_regs(t_process *new, int player_number)
{
	int		i;

	i = 0;
	while (i <= REG_NUMBER + 1)
	{
		new->regs[i] = 0;
		i++;
	}
	new->regs[1] = player_number;
//	return (regs);
}
/*
t_arg		*init_arg(t_process *new)
{
	new = ft_memalloc(sizeof(*new));
	new->v[0] = 0;
	new->v[1] = 0;
	new->v[2] = 0;
	new->type[0] = 0;
	new->type[1] = 0;
	new->type[2] = 0;
	new->args_size = 0;
	return (new);
}
*/

void			init_arg(t_command_args *arg)
{
	arg->v[0] = 0;
	arg->v[1] = 0;
	arg->v[2] = 0;
	arg->type[0] = 0;
	arg->type[1] = 0;
	arg->type[2] = 0;
	arg->args_size = 0;
}

t_process	*init_process(t_vm *vm, int i)
{
	printf("init process of i is: %d\n", i);
	t_process *new;

	new = ft_memalloc(sizeof(*new));
	new->player_number = i * -1;
	printf("new player number is :%d\n", new->player_number);
//	new->curr_op = 0;
	init_arg(&(new->arg));
//	new->pc = NULL;
	new->index = (i - 1) * MEM_SIZE / vm->players;
	init_regs(new, i * -1);
	new->carry = 0;
	new->cycle_counter = 0;
//	new->state = 0;;
	new->process_alive = 0;
	new->player_alive = 0;;
	new->store_vm = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		now_we_are_free(t_process *enya)
{
/*
	player_number
*/
//	free(enya->arg);
	free(enya);
}
#define V vm->processes
void	add_processes(t_vm *vm, int i)
{
	t_vm	*head;

	head = vm;
	printf("new process i is: %d\n", i);
	if (vm->processes == NULL)
	{
		vm->processes = init_process(vm, i);
		printf("NULL the player number is: |%d|, the index is: |%d| \n", V->player_number, V->index);
	}
	else
	{
		while (vm->processes)
		{
			vm->processes = vm->processes->next;
		}
		vm->processes = init_process(vm, i);
		printf(" NOT NULLthe player number is: |%d|, the index is: |%d| \n", V->player_number, V->index);
	}
}

#define P temp->processes

void	controller(t_vm *vm)
{
	int		i;
	int		vm_cycles;
	int		ctd;

	i = vm->players;
	vm->processes = NULL;
	printf("the number of players is: %d\n", vm->players);
	while (i)
	{
		add_processes(vm, i);	
		i--;
	}
	

	vm_cycles = 0;
	ctd = CYCLE_TO_DIE;
	t_vm *temp;
	temp = vm;
/*	while (temp->processes)
	{
	//	printf("the player number is: |%d|, the index is: |%d| \n", P->player_number, P->index);
		P = P->next;
	}
	*/
	temp = vm;
	while (temp->processes)
	{
		if (vm_cycles == ctd)
		{
			kill_processes(&(vm->processes));
			ctd -= CYCLE_DELTA;
		}
		vm_cycles += 1;
		if (vm_cycles == 20)
			break ;
	}
	dummy_testing(vm); // testing store_values
	dump_memory(*vm);
}
