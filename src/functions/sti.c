/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti->c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42->fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:16:48 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 23:49:05 by eliu             ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 3 parameters-> The first one must be a register-> 
**	The other two can be inexes or registers->
**	It's function as follows:
**	sti(r2, %4, %5) copies the content of r2 into
**	the address PC + (4 + 5) % IDX_MOD->
*/

static void	store_big_endian(t_vm *vm, int value, int index)
{
	ft_putendl("	entered big endian");
	char	a;
	char	b;
	char	c;
	char	d;

	a = value & 0xff000000;
	b = value & 0x00ff0000;
	c = value & 0x0000ff00;
	d = value & 0x000000ff;
	vm->memory[index] = a;
	vm->memory[index + 1] = b;
	vm->memory[index + 2] = c;
	vm->memory[index + 3] = d;
	ft_putendl("	exited big endian");
}

int		ft_sti(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("	entered ft_sti");
	int		index1;
	int		index2;

	(void)champ;
	index1 = 0;
	index2 = 0;
	if (reg(process, 0) && any(process, 1) && reg_dir(process, 2))
	{
		store_values(vm, process, jndex, 2);
		if (reg(process, 1))
		{
			//index1 = process->regs[process->arg.v[1]];
			process->arg.v[1] = process->regs[process->arg.v[1]];
		}
		if (reg(process, 2))
		{
			process->arg.v[2] = process->regs[process->arg.v[2]];
		}
		store_big_endian(vm, process->regs[process->arg.v[0]], 
							process->arg.v[1] + process->arg.v[2]);
		ft_putendl("	exited ft_sti with return 0");
		return (0);
	}
	ft_putendl("	exited ft_sti with return 1");
	return (1);
}
