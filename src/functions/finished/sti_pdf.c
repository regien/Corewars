/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:16:48 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 21:10:34 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Takes 3 parameters. The first one must be a register. 
**	The other two can be inexes or registers.
**	It's function as follows:
**	sti(r2, %4, %5) copies the content of r2 into
**	the address PC + (4 + 5) % IDX_MOD.
*/

void		ft_sti_cycles(t_process *process)
{
	process->cycle_counter = 25;
}

// Truncation exists! indecies are halved! 
// Byte code exists! pc += 1 extra

void		ft_sti(t_process *process)
{
	if (reg(process, 0) && all(process, 1) && reg_dir(process, 2))
	{
		// Store 4 bytes in virtual memory. The current method is only accessing 1 byte.
		vm->memory[process->arg.v[1] + process->arg.v[2]] = process->arg.v[0];
	}
}

/*
t_process		*ft_sti(char first, char second, char third)
{
	t_process	*process;

	process = NULL;
	//	If first parameter is a regster && (second and third) are index or reg:
	//	{
	value_at_address(PC + (value_at_address(second) + value_at_address(third)) % INX_MOD) =
	value_at_address(first);

	//	}
	return (process);
}
*/
