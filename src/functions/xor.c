/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor->c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 04:29:31 by eliu              #+#    #+#             */
/*   Updated: 2018/05/28 07:19:47 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 3 parameters. It perorms binary OR '|' between the first two parameters
**	and puts the difference into the third one (not a reg).
**	This operation modifies the carry.
**	sub (r2, r3, r5) subtract the content of r2 and r3 and puts the result into r5.
*/

int		ft_xor(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("	entered ft_xor");
	(void)vm;
	(void)champ;
	if (any(process, 0) && any(process, 1) && reg(process, 2))
	{
		store_values(vm, process, jndex, 3);
		convert_if_register_number_to_value(process, 0);
		convert_if_register_number_to_value(process, 1);
		if ((process->regs[process->arg.v[2]] = 
			(process->arg.v[0] ^ process->arg.v[1]) /* % IDX_MOD */) == 0)
		{
			process->carry = 1;
		}
		else
		{
			process->carry = 0;
		}
		ft_putendl("	exited ft_xor with return 0");
		return (0);
	}
	ft_putendl("	exited ft_xor with return 1");
	return (1);
}
