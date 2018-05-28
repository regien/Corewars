/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi->c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:03:52 by eliu              #+#    #+#             */
/*   Updated: 2018/05/24 00:08:58 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 3 parameters. The first two must be indexes, the third one must be a register.
**	This operation modifies the carry and functions as follows:
**	ldi(3, %4, r1 ) reads IND_SIZE bytes from the address PC + 3 % IDX_MOD , 
**	adds 4 to this value.
**	The sum is named S. 
**	REG_SIZE bytes are read from the address PC + S % IDX_MOD and copied into r1.
**
**	Gerardo's notes:
**	let's put it on revision becuase of the shift handeling
*/

int		ft_ldi(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	s;
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("	entered ft_ldi");
	int		temp;
	int		index;

	(void)champ;
	if (any(process, 0) && reg_dir(process, 1) && reg(process, 2))
	{
		store_values(vm, process, jndex, 3);
		// If parameter is a register, store the value (v[i]) as the value
		// Inside the reigster #
		if (reg(process, 0))
		{
			process->arg.v[0] = process->regs[process->arg.v[0]];
		}
		if (reg(process, 1))
		{
			process->arg.v[1] = process->regs[process->arg.v[1]];
		}
		s = (process->arg.v[0] + process->arg.v[1]) % IDX_MOD;
		if ((process->regs[process->arg.v[2]] = \
			read_2_bytes(vm, process, s, 2)) == 0)
		{
			process->carry = 1;
		}
		else
		{
			process->carry = 0;
		}
		ft_putendl("	exited ft_ldi with return 0");
		return (0);
	}
	ft_putendl("	exited ft_ldi with return 1");
	return (1);
}
