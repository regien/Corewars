/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:33:37 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 21:05:37 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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
	vm = NULL;
	champ = NULL;

	if (any(process, 0) && any(process, 1) && reg(process, 2))
	{
		if ((process.regs[process.arg.v[2]] = 
				process.args.v[0] | process.args.v[1]) == 0)
		{
			process.carry = 1;
		}
		else
		{
			process.carry = 0;
		}
		return (0);
	}
	return (1);
}
