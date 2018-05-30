/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:33:37 by eliu              #+#    #+#             */
/*   Updated: 2018/05/30 03:49:20 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 3 parameters. It performs a binary OR '|' between the two parameters 
**	and stores the result into the third one (which must be a register).
**	This operation modifies the carry.
**	and(r2, %0, r3) puts r2 | 0 into r3.
*/

int		ft_or(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("ft_or\n");
	(void)vm;
	(void)champ;
	if (any(process, 0) && any(process, 1) && reg(process, 2))
	{
		store_values(vm, process, jndex, 3);
		if (reg(process, 0) && reg_bounds(process->arg.v[0]))
			return (1);
		if (reg(process, 1) && reg_bounds(process->arg.v[1]))
			return (1);
		if ((process->regs[process->arg.v[2]] = \
			(process->arg.v[0] | process->arg.v[1]) /* IDX_MOD */) == 0)
		{
			process->carry = 1;
		}
		else
		{
			process->carry = 0;
		}
		printf("process carry is %d\n", process->carry);
		return (0);
	}
	ft_putendl("ft_or did not execute");
	return (1);
}
