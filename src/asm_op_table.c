/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:21:05 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/24 12:21:51 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		get_op_code_2(char *op_name, t_ops *op)
{
	if (!ft_strcmp(op_name, "fork"))
		op->op_code = 12;
	else if (!ft_strcmp(op_name, "lld"))
		op->op_code = 13;
	else if (!ft_strcmp(op_name, "lldi"))
		op->op_code = 14;
	else if (!ft_strcmp(op_name, "lfork"))
		op->op_code = 15;
	else if (!ft_strcmp(op_name, "aff"))
		op->op_code = 16;
	return (op->op_code);
}

int		get_op_code(char *op_name, t_ops *op)
{
	if (!ft_strcmp(op_name, "live"))
		op->op_code = 1;
	else if (!ft_strcmp(op_name, "ld"))
		op->op_code = 2;
	else if (!ft_strcmp(op_name, "st"))
		op->op_code = 3;
	else if (!ft_strcmp(op_name, "add"))
		op->op_code = 4;
	else if (!ft_strcmp(op_name, "sub"))
		op->op_code = 5;
	else if (!ft_strcmp(op_name, "and"))
		op->op_code = 6;
	else if (!ft_strcmp(op_name, "or"))
		op->op_code = 7;
	else if (!ft_strcmp(op_name, "xor"))
		op->op_code = 8;
	else if (!ft_strcmp(op_name, "zjmp"))
		op->op_code = 9;
	else if (!ft_strcmp(op_name, "ldi"))
		op->op_code = 10;
	else if (!ft_strcmp(op_name, "sti"))
		op->op_code = 11;
	else 
		return (get_op_code_2(op_name, op));
	return (op->op_code);
}
