/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 22:55:43 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/29 03:08:19 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Well set_champs is was replaced by the initial parser at the beginning of
** the program so, in a further meeting this functions is going nowhere
** just delete it
**
** CLEAR_VM_MEM
** it was replaced by a 2 lines while loop in init_vm
*/

/*
void	set_champs(t_champ *champ, char *filename)
{
	if (!champ)
		champ = malloc(sizeof(champ));
	champ->fd = open(filename, O_RDONLY);
	champ->plyr_nbr = 0;
	champ->size = 0;
	champ->processes = 0;
}

void	clear_vm_mem(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		vm->memory[i] = 0;
		i++;
	}
	vm->cycles = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
}
*/

t_process	*set_process(char *pc_start, int mem_start, int player_nbr)
{
	t_process	*p;
	int			i;

	if (!pc_start)
		printf("initial pc is weird\n");
	p = malloc(sizeof(t_process));
	p->pc = pc_start;
	p->index = mem_start;
	p->next = NULL; // it was 0
	p->prev = NULL; // it was 0
	i = 0;
	// INITIALIZING REGISTERS
	while (i < 16)
	{
		p->regs[i] = 0;
		i++;
	}
	p->regs[1] = player_nbr * -1;
	// testing_only
	for (i = 0; i < 16; i++)
		printf("p->regs[i] = %d\n", p->regs[i]);
	p->carry = 0;
	p->cycle_counter = 0;
	p->state = FETCH;
	p->live = 0;
	p->curr_op = 0;
	return (p);
}

/*
** modify add process and set_process to:
	- initializes the register
		| everything in arg (t_command_arg)
	- initialize the types
	- initiliaze the arg.v
*/

t_process	*add_process(t_champ *champ, int index)
{
	t_process *new;
	t_process *root;

	if (!(champ && champ->processes))
		return (0);
	root = champ->processes;
	new = set_process(root->pc, index, champ->plyr_nbr);
	new->father_champ = champ;
	new->next = root;
	root->prev = new;
	champ->processes = new;
	return (new);
}

void		kill_process(t_process *p)
{
	if (!p)
		return ;
	if (p->next)
		p->next->prev = p->prev;
	if (p->prev)
		p->prev->next = p->next;
	free(p);
}
