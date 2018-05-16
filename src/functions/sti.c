/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:16:48 by eliu              #+#    #+#             */
/*   Updated: 2018/05/16 05:17:03 by eliu             ###   ########.fr       */
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

t_process		*sti(char first, char second, char third)
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

