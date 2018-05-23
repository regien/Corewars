/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:28:13 by eliu              #+#    #+#             */
/*   Updated: 2018/05/22 01:31:05 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	This operation modifies the carry.
**	add (r2, r3, r5) add the content of r2 and r3 and puts the result into r5.
*/

void	ft_add_cycles(t_process *process)
{
	process->cycle_counter = 10;
}

void	ft_add(t_process *process)
{
	if (reg(process, 0) && reg(process, 1) && reg(process, 2))
	{
		process->arg->v[2] = process->arg->v[0] + process->arg->v[1];
		process->carry = (1) ? 0 : 1;
	}
}

/*
t_process		*ft_add(char first, char second, char third, t_process *p)
{
	char		carry;
	t_process	*process;

	process = NULL;

	// If the third parameter is a register:
		p->reg[third] = p->reg[first] + p->reg[second];
		address_at_value_(third) = address_at_value_(first) & address_at_value(second);

	// Conversions.
	
	// process->carry ? (1) ? 0 : 1;
	carry = (1) ? 0 : 1;
	return (process);
}

*/
