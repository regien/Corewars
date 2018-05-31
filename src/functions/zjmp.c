
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 04:59:36 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 20:18:14 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 1 parameter, which must be an index.
**	It jumps to this index if the carry is worth 1. 
**	Otherwise, it does nothing but consumes the same time.
**	zjmp(%23) if carry equals 1, puts PC + 23 % IDX_MOD into the PC.
*/

//	encoding byte exists
//	Is Alex modifying the PC for zjmp outside of this function?

int		ft_zjmp(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("ft_zjmp\n");
	(void)vm;
	(void)champ;
	if (process->carry == 1)
	{
		store_values(vm, process, jndex, 1);
		process->index = process->arg.v[0] % IDX_MOD;
		ft_putendl("Carry == 1, zjmp success!");
		return (0);
	}
	ft_putendl("Carry == 0, zjmp fail!");
	return (1);
}
