/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:33:37 by eliu              #+#    #+#             */
/*   Updated: 2018/05/28 06:43:34 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Similar to and '&', but performing a binary OR '|'.
*/

/*
**	Takes 3 parameters. It performs a binary OR '|' between the two parameters 
**	and stores the result into the third one (which must be a register).
**	This operation modifies the carry.
**	and(r2, %0, r3) puts r2 | 0 into r3.
*/

int		ft_or(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("	entered ft_or");
	(void)vm;
	(void)champ;
	if (any(process, 0) && any(process, 1) && reg(process, 2))
	{
		store_values(vm, process, jndex, 3);
		if (reg(process, 0))
		{
			printf("the reigster number is: %d\n", process->arg.v[0]);
			printf("the reigster value is: %d\n", process->regs[process->arg.v[0]]);

			process->arg.v[0] = process->regs[process->arg.v[0]];
		}
		printf("TYPE: %d\n", process->arg.type[1]);
		if (reg(process, 1))
		{
			printf("the reigster number is: %d\n", process->arg.v[1]);
			printf("the reigster value is: %d\n", process->regs[process->arg.v[1]]);
			process->arg.v[1] = process->regs[process->arg.v[1]];
		}
		if ((process->regs[process->arg.v[2]] = 
				process->arg.v[0] | process->arg.v[1]) == 0)
		{
			process->carry = 1;
		}
		else
		{
			process->carry = 0;
		}
		ft_putendl("	exited ft_or with return 0");
		return (0);
	}
	ft_putendl("	exited ft_or with return 1");
	return (1);
}
