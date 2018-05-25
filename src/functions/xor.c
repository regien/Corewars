/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 04:29:31 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 21:04:10 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Takes 3 parameters. It perorms binary OR '|' between the first two parameters
**	and puts the difference into the third one (not a reg).
**	This operation modifies the carry.
**	sub (r2, r3, r5) subtract the content of r2 and r3 and puts the result into r5.
*/

void	ft_xor(t_process *process)
{
	if (any(process, 0) && any(process, 1) && reg(process, 2))
	{
		if ((process->reg[process->arg.v[2]] = 
				process->arg.v[0] ^ process->arg.v[1]) == 0)
		{
			process.carry = 1;
		}
		else
		{
			process.carry = 0;
		}
	}
}
