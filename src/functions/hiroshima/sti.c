/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti->c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42->fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:16:48 by eliu              #+#    #+#             */
/*   Updated: 2018/05/29 08:21:08 by eliu             ###   ########.fr       */
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
	unsigned char	a;
	unsigned char	b;
	unsigned char	c;
	unsigned char	d;

	a = value & 0xff000000;
	b = value & 0x00ff0000;
	c = value & 0x0000ff00;
	d = value & 0x000000ff;
	vm->memory[circulate_index(index)] = a;
	vm->memory[circulate_index(index + 1)] = b;
	vm->memory[circulate_index(index + 2)] = c;
	vm->memory[circulate_index(index + 3)] = d;
	ft_putendl("	exited big endian");
}

//handle IDX_MOD of p1 and p2; are we sure?

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
		convert_if_register_number_to_value(process, 1);
		convert_if_register_number_to_value(process, 2);
		store_big_endian(vm, process->regs[process->arg.v[0]], 
						(process->arg.v[1] + process->arg.v[2] % IND_SIZE));
		ft_putendl("	exited ft_sti with return 0");
		return (0);
	}
	ft_putendl("	exited ft_sti with return 1");
	return (1);
}
