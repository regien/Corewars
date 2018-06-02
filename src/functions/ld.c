/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:08:54 by eliu              #+#    #+#             */
/*   Updated: 2018/06/02 00:34:49 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Load takes two parameters, the second must be a register.
**	If the first parameter is a indirect, store the value of REG_SIZE 
**	into the reigster.
**	Else if the second parameter is an direct, go to the address of the value
**	of direct, and read REG_SIZE bytes into the register.
**	Modify carry if the stored value is zero.
*/

/*
**	Loads the value of the first parameter into the second parameter,
**	which must be a register (not the PC). This operation modifies the carry.
**	ld(34, r3) loads the REG_SIZE bytes (4 bytes aka int) starting at the address
**	PC + 34 % IND_MOD into r3. 5 cycles.
*/

// Double check idx_mod;

int		ft_ld(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("ft_ld");
	(void)champ;
	if (dir_ind(process, 0) && reg(process, 1))
	{
		store_values(vm, process, jndex, 2);
		if (reg_bounds(process->arg.v[1]) == 0)
		{
			if (ind(process, 0))
			{
				read_4_bytes(vm, process, process->index + circulate_index(process->arg.v[0]) % IDX_MOD, 0);
			}
			printf("\nThe loaded value is: |%d|\n", process->arg.v[0]);
			if ((process->regs[process->arg.v[1]] = (process->arg.v[0])/* % IDX_MOD*/) == 0)
			{
				process->carry = 1;
			}
			printf("Register value is: |%d|\n", process->arg.v[1]);
		}
		else
		{
			process->carry = 0;
		}
		return (0);
	}
	ft_putendl("ft_load error\n");
	return (1);
}
