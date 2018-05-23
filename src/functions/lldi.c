/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 06:11:20 by eliu              #+#    #+#             */
/*   Updated: 2018/05/20 18:12:06 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Similar to ldi without the %IDX_MOD. This operation modifies the carry.
*/

/*
**	t_process		*ldi(char first, char second, char third);
**	Takes 3 parameters. The first two must be indexes, the third one must be a register.
**	This operation modifies the carry and functions as follows:
**	ldi(3, %4, r1 ) reads IND_SIZE bytes from the address PC + 3 % IDX_MOD , 
**	adds 4 to this value.
**	The sum is named S. 
**	REG_SIZE bytes are read from the address PC + S % IDX_MOD and copied into r1.
*/

t_process		*ft_lldi(char first, char second, char third)
{
	char		S;
	char		carry;
	t_process	*process;

	process = NULL;
	//	If first and second parameter are index, and third is a register:
	//	{
			S = ind_size_bytes_of((address_of(PC)) + 3 % IND_MOD) + 4;
			value_of_address(first) = reg_size_bytes_read(address_of(PC)) + S % IND_MOD;
	//	}

	// process->carry = 1 ? 0 : 1;
	carry = 1 ? 0 : 1;
	return (process);
}
