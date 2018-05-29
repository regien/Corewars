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
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("	entered ft_lfork");
	t_process *new;

	new = NULL; // NULLYFYING this pointer for FLAGS_ERROS
	(void)vm;
	(void)champ;
	if (dir(process, 0))
	{
		store_values(vm, process, jndex, 1);
		process->arg.v[0] = circulate_memory(process->arg.v[0]);
		new = add_process(champ, process->arg.v[0]);
		ft_putendl("	exited ft_lfork with return 0");
		return (0);
	}
	ft_putendl("	exited ft_lfork with return 1");
	return (1);
}
