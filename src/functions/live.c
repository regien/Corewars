/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:06:43 by eliu              #+#    #+#             */
/*   Updated: 2018/05/30 05:38:12 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	I need to add a function that lets the function controller know that
**	a champion is alive due to the processes.
*/
/*
static void	last_to_live(t_vm *vm, int player)
{
	vm->last_to_live = player;
}
*/

static void	show_alive(t_process *process)
{
	ft_printf("A process shows that Player %d (%s) is alive.\n", \
				process->player_alive, "process->name");
}

int			ft_live(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("ft_live:");
//	if (dir(process, 0))
//	{
		store_values(vm, process, jndex, 1);
		printf("stored value of v[0] is: |%d|\n", process->arg.v[0]);
		process->process_alive = 1;
		process->player_alive = process->arg.v[0];
		// This is currently the champ who owns the process. Need to change for
		// The number for who we called live for.
		champ->lives_counted += 1;
		vm->last_to_live = process->arg.v[0];
		printf("vm->last_live = %d <-------- MODIFYED PENDEJADA\n", process->arg.v[0]);
//		vm->total_lives += 1;
		printf("The latest player to call live is player: |%d|\n", vm->last_to_live);
//		last_to_live(vm, process->arg.v[0]);
		show_alive(process);
		ft_putendl("");
		return (0);
//	}
	ft_putendl("live error");
	return (1);
}
