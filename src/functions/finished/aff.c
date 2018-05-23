/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 06:23:58 by eliu              #+#    #+#             */
/*   Updated: 2018/05/22 01:06:32 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Takes 1 register, which must be a register. 
**	Prints stdout :
**	The character whose ASCII code is the content of the register (in base 10).
**	
**	A 256 modulo is applied to this ASCII code.
**	aff(r3) displyas ’*’ if r3 contains 42.
*/

int		ft_aff_cycles(t_process *process)
{
	process->cycle_counter = 2;
}

void	ft_aff(char index)
{
	
	ft_putchar(index % 256);
}
