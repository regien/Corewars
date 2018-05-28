/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:59:20 by eliu              #+#    #+#             */
/*   Updated: 2018/05/28 01:35:23 by eliu             ###   ########.fr       */
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
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
ft_putendl("	entered ft_fork");
	(void)vm;
	(void)champ;

	t_process *new;

	new = NULL; // gerardo: nullyfing this pointer for FLAGS_ERRORS
	if (dir(process, 0))
	{
		store_values(vm, process, jndex, 1);
		//new = add_process(champ, process->index % IDX_MOD);
		ft_putendl("	exited ft_fork with return 0");
		return (0);
	}
	ft_putendl("	exited ft_fork with return 1");
	return (1);
}
