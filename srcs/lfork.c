/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 06:17:20 by eliu              #+#    #+#             */
/*   Updated: 2018/05/16 06:17:31 by eliu             ###   ########.fr       */
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

t_process		*lfork(char index)
{
	t_process	*parent;
	t_process	*child;

	child = parent;
	//	If parameter is an index:
	//	{
			execute_at(address_at(PC) + index);
			
	//	}
	return (child);
}