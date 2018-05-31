/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 06:23:58 by eliu              #+#    #+#             */
/*   Updated: 2018/05/30 04:22:10 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 1 register, which must be a register. 
**	Prints stdout :
**	The character whose ASCII code is the content of the register (in base 10).
**	
**	A 256 modulo is applied to this ASCII code.
**	aff(r3) displyas ’*’ if r3 contains 42.
*/

int		ft_aff(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("ft_aff");
	(void)vm;
	(void)champ;
	if (vm->flags_args.aff == 1)
	{
		find_register(vm, process, process->index + 2, 0);
		if (reg_bounds(process->arg.v[0]))
		{
			process->carry = 0;
			return (1);
		}
		ft_putchar((process->regs[process->arg.v[0]]) % 256);
		return (0);
	}
	ft_putendl("ft_aff did not execute");
	return (1);
}
