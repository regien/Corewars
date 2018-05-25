/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 06:03:09 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 20:48:27 by eliu             ###   ########.fr       */
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

int		ft_lld(t_vm *vm, t_champ *champ, t_process *process)
{
	if (any(process, 0) && reg(process, 1))
	{
		if ((process.reg[process.arg.v[1]] = process.arg.v[0]) == 0)
		{
			process.carry = 1;
		}
		else
		{
			process.carry = 0;
		}
		return (0);
	}
	return (1);
}
