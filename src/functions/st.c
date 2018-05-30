/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:18:56 by eliu              #+#    #+#             */
/*   Updated: 2018/05/29 12:40:38 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 2 paramters. It stores the first parameter's value (which is a reg)
**	into the second (both).
**	// To number:	
**	st (r4, 34) stores the content of r4 at the address PC + 34 % IND_MOD.
**	// To register:	
**	st (r3, r8) copies the content of r3 into r8.
*/

static void	store_big_endian(t_vm *vm, int value, int index)
{
	ft_putendl("	entered big endian");
	unsigned char	a;
	unsigned char	b;
	unsigned char	c;
	unsigned char	d;

	a = (value & 0xff000000) >> 24;
	b = (value & 0x00ff0000) >> 16;
	c = (value & 0x0000ff00) >> 8;
	d = value & 0x000000ff;
	vm->memory[circulate_index(index)] = a;
	vm->memory[circulate_index(index + 1)] = b;
	vm->memory[circulate_index(index + 2)] = c;
	vm->memory[circulate_index(index + 3)] = d;
	ft_putendl("	store big endian");
}

// final results of process->arg.v[1] %= IDX_MOD;

int		ft_st(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("	entered ft_st");
	(void)champ;
	if (reg(process, 0) && reg_ind(process, 1))
	{
		store_values(vm, process, jndex, 2);
		convert_if_register_number_to_value(process, 0);
		if (reg(process, 1))
		{
			process->regs[process->arg.v[1]] = \
			process->regs[process->arg.v[0]];
		}
		else if (ind(process, 1))
		{
			store_big_endian(vm, process->arg.v[0], process->arg.v[1] /* % IDX_MOD */);
		}
		ft_putendl("	exited ft_st with return 0");
		return (0);
	}
	ft_putendl("	exited ft_st with return 1");
	return (1);
}
