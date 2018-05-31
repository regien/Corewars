/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 23:50:39 by eliu              #+#    #+#             */
/*   Updated: 2018/05/30 05:31:42 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	reg_bounds(int reg)
{
	if (1 <= reg && reg <= 16)
		return (0);
	printf("out of register bounds!\n");
	return (1);
}

char	reg(t_process *process, int x)
{
	if (process->arg.type[x] == REG_CODE)
		return (REG_CODE);
	return (0);
}

char	dir(t_process *process, int x)
{
	printf("print this shit = %d\n", process->arg.type[x]);
	if (process->arg.type[x] == DIR_CODE)
		return (DIR_CODE);
	return (0);
}

char	ind(t_process *process, int x)
{
	if (process->arg.type[x] == IND_CODE)
		return (IND_CODE);
	return (0);
}
