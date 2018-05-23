/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:06:43 by eliu              #+#    #+#             */
/*   Updated: 2018/05/21 23:37:51 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_fetch_live(t_process *process)
{
	process->cycle_counter = 10;
}

/*
int		ft_can_call_live(t_vm *virtual_machine, t_process *process)
{
	// double check parameters.	
}
*/

void	ft_live(t_vm *virtual_machine, t_process *process)
{
	process->live = 1;
	carry = 1;
	// Length of instruction.
	process->pc += 4;
}
