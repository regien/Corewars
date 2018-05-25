/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:28:13 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 20:45:24 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	This operation modifies the carry.
**	add (r2, r3, r5) add the content of r2 and r3 and puts the result into r5.
*/

int		ft_add(t_vm *vm, t_champ *champ, t_process *process)
{
	vm = NULL;
	champ = NULL;	
	if (reg(process, 0) && reg(process, 1) && reg(process, 2))
	{
		if ((process->regs[process->arg.v[2]] = 
			process->arg.v[0] + process->arg.v[1]) == 0)
		{
			process->carry = 1;
		}
		else
		{
			process->carry = 0;
		}
		return (0);
	}
	return (1);
}
