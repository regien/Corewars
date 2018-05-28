/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 06:23:58 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 23:20:25 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 1 register, which must be a register. 
**	Prints stdout :
**	The character whose ASCII code is the content of the register (in base 10).
**	
**	A 256 modulo is applied to this ASCII code.
**	aff(r3) displyas ’*’ if r3 contains 42.
*/

int		ft_aff(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("	entered ft_aff");
	(void)vm;
	(void)champ;
	if (reg(process, 0) && vm->flags_args.aff == 1)
	{
		store_values(vm, process, jndex, 1);
		ft_putchar(process->regs[[process->arg.v[0]]] % 256);
		ft_putendl("	exited ft_aff with return 0");
		return (0);
	}
	ft_putendl("	exited ft_aff with return 1");
	return (1);
}
