/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:28:13 by eliu              #+#    #+#             */
/*   Updated: 2018/05/16 04:50:31 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Takes 3 parameters. It perorms binary AND between the first two parameters
**	and puts the sum into the third one (not a reg).
**	This operation modifies the carry.
**	add (r2, r3, r5) add the content of r2 and r3 and puts the result into r5.
*/

t_process		*add(char first, char second, char third)
{
	char		carry;
	t_process	*process;

	process = NULL;

	// If the third parameter is a register:
		address_at_value_(third) = address_at_value_(first) & address_at_value(second);

	// Conversions.
	
	// process->carry ? (1) ? 0 : 1;	
	carry = (1) ? 0 : 1;
	return (process);
}
