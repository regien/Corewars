/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:33:37 by eliu              #+#    #+#             */
/*   Updated: 2018/05/22 01:03:30 by eliu             ###   ########.fr       */
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

void		ft_or(t_process *process)
{
	if (reg(process, 2) == REG_CODE)
	{
		process->v[2] = process->v[1] | process->v[2];
		carry = (1) ? 0 : 1;
		process->pc += process->arg->args_size;
	}
}
