/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 06:03:09 by eliu              #+#    #+#             */
/*   Updated: 2018/05/30 04:11:09 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Similar to ld without the %IDX_MOD. This operation modifies the carry.
*/

/*
**	Loads the value of the first parameter into the second parameter,
**	which must be a register (not the PC). This operation modifies the carry.
**	ld(34, r3) loads the REG_SIZE bytes starting at the address PC + 34 into r3.
*/

int		ft_lld(t_vm *vm, t_champ *champ, t_process *process)
{
	ft_putendl("ft_lld");
	(void)vm;
	(void)champ;
	if (any(process, 0) && reg(process, 1))
	{
		find_and_store_values(vm, process, process->index + 2, 2);
		if (reg(process, 0) && reg_bounds(process->arg.v[0]))
		{	
			process->carry = 0;
			return (1);
		}
		if (reg_bounds(process->arg.v[1]))
		{
			process->carry = 0;
			return (1);
		}
		convert_if_register_number_to_value(process, 0);
		if (ind(process, 0))
		{
			read_2_bytes(vm, process, process->arg.v[0] + process->index, 0);
		}
		if ((process->regs[process->arg.v[1]] = process->arg.v[0]) == 0)
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
	ft_putendl("ft_lld did not execute properly");
	return (1);
}
