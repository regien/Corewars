/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:59:20 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 20:41:44 by eliu             ###   ########.fr       */
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
	vm = NULL;

	t_process *new;
	if (dir(process, 0))
	{
		new = add_process(champ, process->index % IDX_MOD);
		return (0);
	}
	return (1);
}
