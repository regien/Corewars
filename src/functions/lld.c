/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 06:03:09 by eliu              #+#    #+#             */
/*   Updated: 2018/05/20 18:11:58 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Similar to ld without the %IDX_MOD. This operation modifies the carry.
*/

/*
**	Loads the value of the first parameter into the second parameter,
**	which must be a register (not the PC). This operation modifies the carry.
**	ld(34, r3) loads the REG_SIZE bytes starting at the address PC + 34 into r3.
*/

//	t_process		*process(char first, char second);

t_process		*ft_ldd(char first, char second)
{
	char		carry;
	t_process	*process;

	process = NULL;

	//	If second parameter is a register:
	//	{
			
			value_at_address(second) = size_of_reg_bytes(PC) + value_at_address(first);

	//	}

	//	t_process->carry = 1 ? 0 : 1;
	carry = 1 ? 0 : 1;
	return (process);
}
