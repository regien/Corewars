/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 22:55:43 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/26 19:25:25 by gmalpart         ###   ########.fr       */
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

t_process	*set_process(char *pc_start, int mem_start)
{
	t_process	*p;
	int			i;

	if (!pc_start)
		printf("initial pc is weird\n");
	p = malloc(sizeof(t_process));
	p->pc = pc_start;
	p->index = mem_start;
	p->next = 0;
	p->prev = 0;
	i = 0;
	while (i < 16)
	{
		p->regs[i] = -1;
		i++;
	}
	p->carry = 0;
	p->cycle_counter = 0;
	p->state = FETCH;
	p->live = 0;
	p->curr_op = 0;
	return (p);
}

t_process	*add_process(t_champ *champ, int index)
{
	t_process *new;
	t_process *root;

	if (!(champ && champ->processes))
		return (0);
	root = champ->processes;
	new = set_process(root->pc, index);
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
