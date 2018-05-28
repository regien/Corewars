/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and->c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 04:31:44 by eliu              #+#    #+#             */
/*   Updated: 2018/05/28 06:30:20 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 3 parameters. It performs a binary AND '&' between the two parameters 
**	and stores the result into the third one (which must be a register).
**	This operation modifies the carry.
**	and(r2, %0, r3) puts r2 & 0 into r3.
*/

int		ft_and(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("	entered ft_and");
	(void)vm;
	(void)champ;
	if (any(process, 0) && any(process, 1) && reg(process, 2))
	{
		store_values(vm, process, jndex, 3);
		if (reg(process, 0))
		{
			printf("the register number is: %d\n", process->arg.v[0]);
			printf("the register value is: %d\n", process->regs[process->arg.v[0]]);
			process->arg.v[0] = process->regs[process->arg.v[0]];
		}
		if (reg(process, 1))
		{
			printf("the register number is: %d\n", process->arg.v[1]);
			printf("the register value is: %d\n", process->regs[process->arg.v[1]]);
			process->arg.v[1] = process->regs[process->arg.v[1]];
		}
		int i = 0;
		while (i < 3)
		{
			printf("stored values:\n process->arg.[%d] = %d\n\n\n", i, process->arg.v[i]);
			i++;
		}
		if ((process->regs[process->arg.v[2]] = 
				process->arg.v[0] & process->arg.v[1]) == 0)
		{
			process->carry = 1;
		}
		else
		{
			process->carry = 0;
		}
		ft_putendl("	exited ft_and with return 0");
		return (0);
	}
	ft_putendl("	exited ft_and with return 1");
	return (1);
}
