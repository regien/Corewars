/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 06:17:20 by eliu              #+#    #+#             */
/*   Updated: 2018/06/02 00:33:52 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Similar to fork without the %IDX_MOD. This operation modifies the carry.
*/

/*
**	t_process	*fork(char index);
**	Takes 1 parameter, which must be an index. 
**	It creates a new program that inherits different states from the parent. 
**	This program is executed at the address PC + first parameter % IDX_MOD.
*/

//	Truncation exists

// Double check return values of add_process

int		ft_lfork(t_vm *vm, t_champ *champ, t_process *process)
{
	ft_putendl("ft_long_fork");
//	t_process *new;

//	new = NULL; // NULLYFYING this pointer for FLAGS_ERROS
	read_2_bytes(vm, process, process->index + 1, 0);
//	new = add_process(champ, circulate_index(process->arg.v[0]));
//	champ->processes = add_process(champ, circulate_index(process->arg.v[0]));
	add_process(champ, circulate_index(process->index + process->arg.v[0]));
	copy_registers(champ->processes->next, champ->processes);
	return (1);
}
