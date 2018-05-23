/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:34:00 by eliu              #+#    #+#             */
/*   Updated: 2018/05/22 01:33:11 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Takes 3 parameters. It perorms binary AND between the first two parameters
**	and puts the difference into the third one (not a reg).
**	This operation modifies the carry.
**	sub (r2, r3, r5) subtract the content of r2 and r3 and puts the result into r5.
*/

void	ft_sub_cycles(t_process *process)
{
	process->cycle_counter = 10;
}

void	ft_sub(t_process *process)
{
	if (reg(process, 0) && reg(process, 1) && reg(process, 2))
	{
		process->arg->v[2] = process->arg[0] + process->arg[1];
		process->carry = (1) ? 0 : 1;
	}
}


/*
t_process		*ft_sub(char first, char second, char third)
{
	char		carry;
	t_process	process;

	process = NULL;

	// if the the third parameter is a register:
		addres_at_value_(third) = address_at_value(first) & address_at_value(second);
	// Conversions.
	
	// s_process->carry ? (1) ? 0 : 1;
	carry = (1) ? 0 : 1;
	return (process);
}

*/
