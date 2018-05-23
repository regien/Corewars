/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:59:20 by eliu              #+#    #+#             */
/*   Updated: 2018/05/22 14:57:05 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Takes 1 parameter, which must be an index. 
**	It creates a new program that inherits different states from the parent. 
**	This program is executed at the address PC + first parameter % IDX_MOD.
*/

//	What is a different state from parent that it inherents?

void		ft_fork_cylces(t_process *process)
{
	process->cylcle_counter = 800;
}

t_process	*ft_fork(t_champ *champ, t_process *process, int index)
{
	t_process *new;

	new = add_process(champ, index);
	return (child);
}
