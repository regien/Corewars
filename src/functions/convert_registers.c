/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_registers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 00:38:09 by eliu              #+#    #+#             */
/*   Updated: 2018/05/29 00:47:39 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	register_number_to_value(t_process *process, int arg)
{
	int	reg_number;

	if (0 < arg && arg <= 2)
	{
		reg_number = process->arg.v[arg];
		if (process->arg.type[arg] == REG_CODE)
		{
			process->arg.v[arg] = process->regs[reg_number];
		}
	}
}
