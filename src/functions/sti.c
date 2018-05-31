/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti->c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42->fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:16:48 by eliu              #+#    #+#             */
/*   Updated: 2018/05/30 20:03:22 by gmalpart         ###   ########.fr       */
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

//handle IDX_MOD of p1 and p2; are we sure?

int		ft_sti(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("ft_sti");
	int		index1;
	int		index2;

	(void)champ;
	index1 = 0;
	index2 = 0;
	if (reg(process, 0) && any(process, 1) && reg_dir(process, 2))
	{
//		store_values(vm, process, jndex, 3);
		store_values(vm, process, jndex, 3);
		if (reg(process, 0) && reg_bounds(process->arg.v[0]))
			return (1);
		if (reg(process, 1) && reg_bounds(process->arg.v[1]))
			return (1);
		if (reg(process, 2) && reg_bounds(process->arg.v[2]))
			return (1);
		convert_if_register_number_to_value(process, 0);
		convert_if_register_number_to_value(process, 1);
		convert_if_register_number_to_value(process, 2);
		printf("BIG ENDIAN |%d|\n", process->arg.v[0]);
		store_big_endian(vm, process->arg.v[0], \
						((process->arg.v[1] + process->arg.v[2])) % IDX_MOD + process->index);
		return (0);
	}
	ft_putendl("ft_sti did not execute");
	return (1);
}
