/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:59:20 by eliu              #+#    #+#             */
/*   Updated: 2018/06/01 23:04:49 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 1 parameter, which must be an index. 
**	It creates a new program that inherits different states from the parent. 
**	This program is executed at the address PC + first parameter % IDX_MOD.
*/

//	What is a different state from parent that it inherents?
//	double check all 
int		ft_fork(t_vm *vm, t_champ *champ, t_process *process)
{
	ft_putendl("ft_fork");
//	t_process *new;

//	new = NULL; // gerardo: nullyfing this pointer for FLAGS_ERRORS
	
	read_2_bytes(vm, process, process->index + 1, 0);
//	champ->processes = add_process(champ, \
//			circulate_index(process->arg.v[0] % IDX_MOD));
	add_process(champ, circulate_index(process->arg.v[0] % IDX_MOD));
	copy_registers(champ->processes->next, champ->processes);
	printf("printing here instead\n");
	return (1);
}
