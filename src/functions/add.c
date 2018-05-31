/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:28:13 by eliu              #+#    #+#             */
/*   Updated: 2018/05/30 22:58:49 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	This operation modifies the carry.
**	add (r2, r3, r5) add the content of r2 and r3 and puts the result into r5.
*/

int		ft_add(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("ft_add");
	(void)vm;
	(void)champ;
	if (reg(process, 0) && reg(process, 1) && reg(process, 2))
	{
		store_values(vm, process, jndex, 3);
		if (reg_bounds(process->arg.v[0]) || reg_bounds(process->arg.v[1]) ||
			(reg_bounds(process->arg.v[2])))
		{
			process->carry = 0;
			return (1);
		}
		if ((process->regs[process->arg.v[2]] = \
			(process->regs[process->arg.v[0]]) + \
			(process->regs[process->arg.v[1]])) == 0)
		{
			process->carry = 1;
		}
		else
		{
			process->carry = 0;
		}
		return (0);
	}
	ft_putendl("ft_add did not execute");
	return (1);
}
