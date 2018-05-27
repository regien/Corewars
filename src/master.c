/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 22:21:28 by eliu              #+#    #+#             */
/*   Updated: 2018/05/26 22:09:36 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	I need to be able to hold all champions. Which will hold all processes.
**	Which will hold all pc's so they can find instructions. If they do find
**	instructions, wait for their number of cycles and and attempt to execute
**	when the cycle count is up.
*/

/*
**	What happens if a function calls live AT cycle_to_die?
*/

int		process_with_lowest_cycle_counter(t_process *processes, int cycles_left_to_die)
{
	int		lowest_cycles;

	cycles = parse_all_processes_return_lowest_cycle(processes);
	if (lowest_cycles < cycles_left_to_die)
	{
		return (lowest_cycles);
	}
	else if (lowest_cycles > cycles_left_to_die)
	{
		return (cylces_left_to_die);
	}
}

/*
**	This is basically lst_remove_if function from beginner's exam.
*/

t_process	*natural_selection(t_process *processes)
{
	t_process	*head;
	t_process	*temp;

	head = processes;
	while (processes->next)
	{
		temp = processes;
		if (processes->live == 0)
		{
			if (head == temp)
			{
				head = processes->next;
				kill_process(processes);
			}
			else
			{
				kill_process();
			}
		}
		processes = processes->next;
	}
	return (evolution);
}

t_process	*kill_processes(t_process *population)
{
	return (natural_selection(population));
}

/*
**	Iterates through all champions to determine unique champions left alive.
*/

int		champs_alive(processes)
{
	int champs[MAX_PLAYERS];

	while (processes->next)
	{
		processes->player_number;

	}
}

// we read the ACB (encoding byte at the moment of execution)

int		ft_fight()
{	
	while (!(all_process_alive))
//	while (champs_alive(processes) != 1)
	{
		// gerardo | check it 
		if (cycles >= CYCLE_TO_DIE)
		{
			kill_processes(all_processes_without_live);
			cycle_to_die = cycle_to_die - delta_cycle;
		}
		attempt_execute_functions_at_proper_cycle_count();
		cycles += 1;
		//cycles = cycles + process_with_lowest_cycle_counter();
	}	
	declare_winner();
}

