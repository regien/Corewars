/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 23:50:39 by eliu              #+#    #+#             */
/*   Updated: 2018/06/02 16:02:06 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	reg(t_process *process, int x)
{
	if (process->arg.type[x] == REG_CODE)
	{	printf("Argument: |%d| is a register\n", x);
		return (REG_CODE);
	}
	return (0);
}

char	dir(t_process *process, int x)
{
	if (process->arg.type[x] == DIR_CODE)
	{
		printf("Argument: |%d| is an direct\n", x);
		return (DIR_CODE);
	}
	return (0);
}

char	ind(t_process *process, int x)
{
	if (process->arg.type[x] == IND_CODE)
	{
		printf("Argument: |%d| is a indirect\n", x);
		return (IND_CODE);
	}
	return (0);
}
