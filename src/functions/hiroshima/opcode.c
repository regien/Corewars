/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 22:18:53 by eliu              #+#    #+#             */
/*   Updated: 2018/05/26 19:19:46 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		validate_opcode(char encoding_byte)
{
	
}

char	find_op_code(t_vm *vm, int index)
{
	char	encoding_byte;
	
	encoding_byte = vm[(index + 1) % MEM_SIZE];
	return (validate_opcode(encoding_byte));
}
