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

void	convert_if_register_number_to_value(t_process *process, int arg)
{
	int	reg_number;

	if (0 <= arg && arg <= 2 && process->arg.type[arg] == REG_CODE)
	{
		reg_number = process->arg.v[arg];
		if (1 <= reg_number && reg_number <= 16)
		{
			process->arg.v[arg] = process->regs[reg_number];
		}
	}
}
