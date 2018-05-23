/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 04:31:44 by eliu              #+#    #+#             */
/*   Updated: 2018/05/22 01:03:12 by eliu             ###   ########.fr       */
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

void		*ft_and(t_process *process)
{
	if (reg(process, 2) == REG_CODE)
	{
		v[2] = v[0] & v[1];
		process->carry = (1) ? 0 : 1;
		process->pc += process->arg->args_size;
	}
}
