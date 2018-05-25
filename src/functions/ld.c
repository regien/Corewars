/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:08:54 by eliu              #+#    #+#             */
/*   Updated: 2018/05/24 12:27:39 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Loads the value of the first parameter into the second parameter,
**	which must be a register (not the PC). This operation modiefies the carry.
**	ld(34, r3) loads the REG_SIZE bytes (4 bytes aka int) starting at the address PC
**	PC + 34 % IND_MOD into r3. 5 cycles.
*/

void	read_from_vm(t_vm *vm, t_process *process, int r, int index)
{
	process.regs[r] = vm.memory[index % MEM_SIZE] << 24;
	process.regs[r] += vm.memory[(index + 1) % MEM_SIZE] << 16;
	process.regs[r] += vm.memory[(index + 2) % MEM_SIZE] << 8;
	process.regs[r] += vm.memory[(index + 3) % MEM_SIZE];
}

/*
**	process.regs has -1
*/

int		ft_ld(t_vm *vm, t_champ *champ, t_process *process)
{
	champ = NULL;
	if (dir_ind(process, 0) && reg(process, 1))
	{
		if (dir(process, 0))
		{
			process.regs[process.arg.v[1] - 1] = process.arg.v[0];
		}
		else if (ind(process, 0))
		{
			read_from_vm(vm, process, process.arg.v[1] - 1, process.index);
		}
		if (process.reg[process.v[1] - 1] == 0)
		{
			process.carry = 1;
		}
		else
		{
			process.carry = 0;
		}
		return (0);
	}
	return (1);
}
