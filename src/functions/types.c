/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 23:50:39 by eliu              #+#    #+#             */
/*   Updated: 2018/05/22 00:16:47 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

char	reg(t_process *process, int x)
{
	if (process->type[x] == 'r')
		return (REG_CODE);
	return (-1);
}

char	dir(t_process *process, int x)
{
	if (process->type[x] == 'd')
		return (DIR_CODE);
	return (-1);
}

char	ind(t_process *process, int x)
{
	if (process->type[x] == 'i')
		return (IND_CODE);
	return (-1);
}
