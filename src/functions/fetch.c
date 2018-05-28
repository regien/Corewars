/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:26:02 by eliu              #+#    #+#             */
/*   Updated: 2018/05/27 16:45:36 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Fetch fuction returns a 0 if found a valid op_code (1-16) and 1 otherwise.
*/

int		valid_op_code(char op_code)
{
	if (0 < op_code && op_code <= MAX_OP_CODES)
	{
		return (0);
	}
	return (1);
}

int		fetch(t_vm *vm, t_process *process)
{
	if (valid_op_code(vm->memory[process->index]))
	{
		return (0);	
	}
	// Should I add a fucntion that automatically increments index by 1
	// If I don't find a valid op_code? I'm going to have to do it somewhere else
	// If I don't do it here actually.
	(process->index)++;
	return (1);
}

void	fetch_all(t_vm *vm, t_process *all)
{

}

/*

void	fetch_next(t_vm *vm, t_process *process)
{
	// Something here.
}

*/
