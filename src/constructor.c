/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 22:55:43 by adubugra          #+#    #+#             */
/*   Updated: 2018/06/01 23:04:19 by eliu             ###   ########.fr       */
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
**
** REMEMBER To copy the register from the parent processes to the child
** process
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
//	p->prev = NULL; // it was 0
	i = 0;
	// INITIALIZING REGISTERS
	while (i < 16)
	{
		p->regs[i] = 0;
		i++;
	}
	p->regs[1] = player_nbr * -1;
	// testing_only <-- erase me
	for (i = 0; i < 16; i++)
		printf("p->regs[i] = %d\n", p->regs[i]);
	// testing_end <-- erase me
	p->carry = 0;
	p->cycle_counter = 0;
	p->process_alive = 0;
	p->state = FETCH;
	p->live = 0;
	p->curr_op = 0;
	p->contador_delete_me = 0; // DELETE ME
	return (p);
}


//void		copy_registers()


// this is the new head
t_process	*add_process(t_champ *champ, int index)
{
	t_process *new;
	t_process *root;

	if (!(champ && champ->processes))
	{
		ft_putendl("Constructor.c : Setting a new process failed!\n");
		return (NULL);
	}	
	printf("Contructor.c : the index of where we are setting the \
			new process is: |%d|\n", index);
	root = champ->processes;
	new = set_process(root->pc, index, champ->plyr_nbr);
	new->father_champ = champ;
	new->next = root;
	// here copy the registers of the next node (old head)
	champ->processes = new;
	return (new);
}
