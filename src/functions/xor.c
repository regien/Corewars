/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor->c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 04:29:31 by eliu              #+#    #+#             */
/*   Updated: 2018/05/30 03:50:32 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 3 parameters. It perorms binary OR '|' between the first two parameters
**	and puts the difference into the third one (not a reg).
**	This operation modifies the carry.
**	sub (r2, r3, r5) subtract the content of r2 and r3 and puts the result into r5.
*/

int		ft_xor(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("ft_xor");
	(void)vm;
	(void)champ;
	if (any(process, 0) && any(process, 1) && reg(process, 2))
	{
		store_values(vm, process, jndex, 3);
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
			read_4_bytes(vm, process, (process->arg.v[0] + process->index) /* % IDX_MOD */, 0);
		}
		if (ind(process, 1))
		{
			read_4_bytes(vm, process, (process->arg.v[1] + process->index) /* % IDX_MOD */, 1);
		}
		if ((process->regs[process->arg.v[2]] = 
			(process->arg.v[0] ^ process->arg.v[1]) /* % IDX_MOD */) == 0)
		{
			process->carry = 1;
		}
		else
		{
			process->carry = 0;
		}
		printf("process carry is |%d|\n", process->carry);
		return (0);
	}
	ft_putendl("ft_xor did not execute");
	return (1);
}
