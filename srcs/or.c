/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:33:37 by eliu              #+#    #+#             */
/*   Updated: 2018/05/16 04:39:52 by eliu             ###   ########.fr       */
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

t_process		*or(char first, char second, char third)
{
	char		carry;
	t_process	*process;

	process = NULL;

	// Conversions.

	// If the third parameter is a register:
		addres_at_vlaue(third) = address_at_value(first) | address_at_value(second);
	// s_process->carry ? (1) ? 0 : 1;
	carry = (1) ? 0 : 1;
	return (process);
}
