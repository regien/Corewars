/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:18:56 by eliu              #+#    #+#             */
/*   Updated: 2018/05/30 22:54:31 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 2 parameters. The first must be a register. Second is REG or IND.
**	If the 2nd arg is a register, overwrite reg2 with value of reg1.
**	Else if the 2nd arg is an IND, store r1 at the address of
**	PC + value(IND) % IDX_MOD.
*/

/*
**	Takes 2 paramters. It stores the first parameter's value (which is a reg)
**	into the second.
**	// To number:	
**	st (r4, 34) stores the content of r4 at the address PC + 34 % IDX_MOD.
**	// To register:	
**	st (r3, r8) copies the content of r3 into r8.
*/

int		ft_st(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	printf("ft_st: original address = |%d|, parameter reading address: |%d| ", process->index, jndex);
	ft_putendl("ft_st");
	(void)champ;
	if (reg(process, 0) && reg_ind(process, 1))
	{
		store_values(vm, process, jndex, 2);
		if (reg_bounds(process->arg.v[0]) == 1)
		{
			process->carry = 0;
			return (1);
		}
		if (reg(process, 1))
		{
			if (reg_bounds(process->arg.v[1]) == 1)
			{
				process->carry = 0;
				return (1);
			}
			process->regs[process->arg.v[1]] = \
			process->regs[process->arg.v[0]];
		}
		else if (ind(process, 1))
		{
			convert_if_register_number_to_value(process, 0);
			store_big_endian(vm, process->arg.v[0], (process->arg.v[1] % IDX_MOD) + process->index);
		}
		return (0);
	}
	ft_putendl("ft_st no exeuction\n");
	return (1);
}
