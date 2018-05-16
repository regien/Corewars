/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:08:54 by eliu              #+#    #+#             */
/*   Updated: 2018/05/16 04:46:55 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Loads the value of the first parameter into the second parameter,
**	which must be a register (not the PC). This operation modiefies the carry.
**	ld(34, r3) loads the REG_SIZE bytes starting at the address PC
**	PC + 34 % IND_MOD into r3.
*/

t_process		*ld(char first, char second)
{
	char		carry;
	t_process	*process;

	process = NULL;

	// Conversions.

	// If second parameter is a register:	
		load(REG_SIZE_at_(pc) + (first % IND_MOD), value_at_address_of_(second));
	
	
	// Turning true to false, and false to true.	
	// t_process->carry = (1) ? 0 : 1;
	carry = (1) ? 0 : 1;
	return (process);
}
