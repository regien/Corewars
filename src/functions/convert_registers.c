/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_registers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 00:38:09 by eliu              #+#    #+#             */
/*   Updated: 2018/05/30 05:45:30 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_regs(int a[])
{
	int i = 0;
	while (i <= 16)
	{
		printf("| register %d : %d |\n", i, a[i]);
		i++;
	}
}

char	reg_bounds(int reg)
{
	if (1 <= reg && reg <= 16)
		return (0);
	printf("out of register bounds!\n");
	return (1);
}

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
