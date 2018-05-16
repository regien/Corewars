/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 04:59:36 by eliu              #+#    #+#             */
/*   Updated: 2018/05/16 05:03:43 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Takes 1 parameter, which must be an index.
**	It jumps to this index if the carry is worth 1. 
**	Otherwise, it does nothing but consumes the same time.
**	zjmp(%23) if carry equals 1, puts PC + 23 % IDX_MOD into the PC.
*/

t_process	*zjmp(char index)
{
	//	Only executes if carry is 1:
	//	{
			PC = PC + value_at_address_of(index) % IDX_MOD;
	//	}
	
}
