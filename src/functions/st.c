/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:18:56 by eliu              #+#    #+#             */
/*   Updated: 2018/05/25 19:02:01 by eliu             ###   ########.fr       */
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
	char	a;
	char	b;
	char	c;
	char	d;

//	printf("the value is: %d\n the index is: %d\n", value, index);
	a = value & 0xff000000;
	b = value & 0x00ff0000;
	c = value & 0x0000ff00;
	d = value & 0x000000ff;
	vm->memory[index] = a;
	vm->memory[index + 1] = b;
	vm->memory[index + 2] = c;
	vm->memory[index + 3] = d;
	ft_putendl("	store big endian");
}

int		ft_st(t_vm *vm, t_champ *champ, t_process *process)
{
	ft_putendl("	entered ft_st");

	(void)champ;
	if (reg(process, 0) && reg_ind(process, 1))
	{
		if (reg(process, 1))
		{
			process->regs[process->arg.v[1] - 1] = 
				process->regs[process->arg.v[0] - 1];
		}
		else if (ind(process, 1))
		{
			printf("the value is: %d\n the index is: %d\n", process->arg.v[0], process->arg.v[1]);
			store_big_endian(vm, process->arg.v[0], process->arg.v[1] % IDX_MOD);
		}
		ft_putendl("	exited ft_st with return 0");
		return (0);
	}
	ft_putendl("	exited ft_st with return 1");
	return (1);
}
