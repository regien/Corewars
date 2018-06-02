/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 04:31:44 by eliu              #+#    #+#             */
/*   Updated: 2018/05/30 03:48:21 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 3 parameters. It performs a binary AND '&' between the two parameters 
**	and stores the result into the third one (which must be a register).
**	This operation modifies the carry.
**	and(r2, %0, r3) puts r2 & 0 into r3.
*/

// First arg can be anything
// If reg, take the value of process->regs[]
// If dir, take the value of a non truncated read 4 bytes. 
// if ind, take the value of read 2 bytes, go to that address, and read 4 bytes.

int		ft_and(t_vm *vm, t_champ *champ, t_process *process)
{
	ft_putendl("ft_and");
	(void)champ;
	if (any(process, 0) && any(process, 1) && reg(process, 2))
	{
		store_values(vm, process, process->index + 2, 3);
		if (reg(process, 0) && reg_bounds(process->arg.v[0]))
		{	
			process->carry = 0;
			return (1);
		}
		if (reg(process, 1) && reg_bounds(process->arg.v[1]))
		{
			process->carry = 0;
			return (1);
		}
		if (ind(process, 0))
		{
			read_4_bytes(vm, process, (process->arg.v[0] + process->carry) /*% IDX_MOD*/, 0);
		}
		if (ind(process, 1))
		{
			read_4_bytes(vm, process, (process->arg.v[1] + process->carry) /*% IDX_MOD*/, 1);
		}
		if ((process->regs[process->arg.v[2]] = \
			(process->arg.v[0] & process->arg.v[1])/* % IDX_MOD */) == 0)
		{
			process->carry = 1;
		}
		else
		{
			process->carry = 0;
		}
		printf("carry is :%d\n", process->carry);
		return (0);
	}
	ft_putendl("ft_and did not execute");
	return (1);
}
