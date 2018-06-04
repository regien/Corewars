/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 16:33:25 by eliu              #+#    #+#             */
/*   Updated: 2018/06/03 16:47:10 by eliu             ###   ########.fr       */
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

//handle IDX_MOD of p1 and p2; are we sure? are we adding process index?

int		ft_sti(t_vm *vm, t_champ *champ, t_process *process)
{
	ft_putendl("ft_sti");
	(void)champ;
	if (reg(process, 0) && any(process, 1) && reg_dir(process, 2))
	{
		find_and_store_values(vm, process, process->index + 2, 3);
		if (reg(process, 0) && reg_bounds(process->arg.v[0]))
			return (1);
		if (reg(process, 1) && reg_bounds(process->arg.v[1]))
			return (1);
		if (reg(process, 2) && reg_bounds(process->arg.v[2]))
			return (1);
		convert_if_register_number_to_value(process, 0);
		convert_if_register_number_to_value(process, 1);
		convert_if_register_number_to_value(process, 2);


		if (ind(process, 1))
		{
			read_2_bytes(vm, process, (process->arg.v[1] + process->index) /* % IDX_MOD */, 1);
		}
		store_big_endian(vm, process->arg.v[0], \
						(process->index + (process->arg.v[1] + process->arg.v[2])) /*% IDX_MOD*/);
		return (0);
	}
	ft_putendl("ft_sti did not execute");
	return (1);
}
