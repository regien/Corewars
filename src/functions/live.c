/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:06:43 by eliu              #+#    #+#             */
/*   Updated: 2018/05/29 01:08:34 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	I need to add a function that lets the function controller know that
**	a champion is alive due to the processes.
*/

static void	last_to_live(t_vm *vm, int player)
{
	if (0 < player && player <= 5)
		vm->last_to_live = player;
}

static void	show_alive(t_process *process)
{
	ft_printf("A process shows that Player %d %s is alive.\n", \
				process->plyr_nbr, process->name);
}

int			ft_live(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("	entered ft_live");
	(void)vm;
	(void)champ;
	if (dir(process, 0))
	{
		store_values(vm, process, jndex, 1);
		process->process_alive = 1;
		process->player_alive = process->arg.v[0];
		last_to_live(vm, process->arg.v[0]);
//		show_alive(process);
		// process->index += args_size;
		// process->index += 5;
		return (0);
		ft_putendl("	exited ft_live with return 0");
	}
	ft_putendl("	exited ft_live with return 1");
	return (1);
}
