/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:59:20 by eliu              #+#    #+#             */
/*   Updated: 2018/05/16 05:59:57 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Takes 1 parameter, which must be an index. 
**	It creates a new program that inherits different states from the parent. 
**	This program is executed at the address PC + first parameter % IDX_MOD.
*/

//	What is a different state from parent that it inherents?

t_process	*fork(char index)
{
	t_process	*parent;
	t_process	*child;

	child = parent;
	// If parameter is an index:
	//	{
			execute_at_(address_of(PC) + index % IND_MOD);
	//	}
	return (child);
}