/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 04:29:31 by eliu              #+#    #+#             */
/*   Updated: 2018/05/16 04:55:35 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Takes 3 parameters. It perorms binary OR '|' between the first two parameters
**	and puts the difference into the third one (not a reg).
**	This operation modifies the carry.
**	sub (r2, r3, r5) subtract the content of r2 and r3 and puts the result into r5.
*/

t_process		*xor(char first, char second, char third)
{
	char		carry;
	t_process	*process;
		
	process = NULL;
	// If the third parameter is a register: 
	//	{
			// Conversions.	
			third = value_at_addres_of(first) | value_at_address_of(second);
	//	}
	// t_process->carry = (1) ? 0 : 1;
	carry = (1) ? 0 : 1;
	return (process);
}