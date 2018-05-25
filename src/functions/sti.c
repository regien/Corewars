/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:16:48 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 23:49:05 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Takes 3 parameters. The first one must be a register. 
**	The other two can be inexes or registers.
**	It's function as follows:
**	sti(r2, %4, %5) copies the content of r2 into
**	the address PC + (4 + 5) % IDX_MOD.
*/

static void	store_big_endian(t_vm *vm, int value, int index)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = value & 0xff000000;
	b = value & 0x00ff0000;
	c = value & 0x0000ff00;
	d = value & 0x000000ff;
	vm.memory[index] = a;
	vm.memory[index + 1] = b;
	vm.memory[index + 2] = c;
	vm.memory[index + 3] = d;
}

int		ft_sti(t_vm *vm, t_champ *champ, t_process *process)
{
	int		index1;
	int		index2;

	champ = NULL;
	if (reg(process, 0) && reg_ind(process, 1))
	{
		if (reg(process, 1))
		{
			index1 = process.regs[process.arg.v[1] - 1];
		}
		else if (ind(process, 1))
		{
			index1 = process.arg.v[1];
		}
		if (reg(process, 2))
		{
			index2 = process.regs[process.arg.v[2] - 1];
		}
		else if (ind(process, 2))
		{
			index2 = process.arg.v[2];
		}
		store_big_endian(vm, process.regs[process.arg.v[0]], index1 + index2);
		return (0);
	}
	return (1);
}
