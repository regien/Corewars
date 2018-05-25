/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 06:17:20 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 20:42:50 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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
	t_process *new;

	vm = NULL;
	champ = NULL;
	if (dir(process, 0))
	{
		new = add_process(champ, process.index);
		return (0);
	}
	return (1);
}
