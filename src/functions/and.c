/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 04:31:44 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 20:54:01 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Takes 3 parameters. It performs a binary AND '&' between the two parameters 
**	and stores the result into the third one (which must be a register).
**	This operation modifies the carry.
**	and(r2, %0, r3) puts r2 & 0 into r3.
*/

/*
** Don't really need this piece of validation.
*/
/*
int			validate_args(t_command_args args)
{
	if (type[0] == 'r' && type[1] == 'r' && type[2] == 'r')
	{
		return (0);
	}
	return (1);
}
*/


int		ft_and(t_vm *vm, t_champ *champ, t_process *process)
{
	vm = NULL;
	champ = NULL;
	if (any(process, 0) && any(process, 1) && reg(process, 2))
	{
		if ((process.regs[process.arg.v[2]] = 
				process.arg.v[1] & process.arg.v[0]) == 0)
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
