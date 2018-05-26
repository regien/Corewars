/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_init_ops2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:50:04 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/25 16:15:02 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	asm_set_ops_accepted_args_3(t_op *ops)
{
	ops[0].accepted_args[2] = 0;
	ops[0x1].accepted_args[2] = 0;
	ops[0x2].accepted_args[2] = 0;
	ops[0x3].accepted_args[2] = T_REG;
	ops[0x4].accepted_args[2] = T_REG;
	ops[0x5].accepted_args[2] = T_REG;
	ops[0x6].accepted_args[2] = T_REG;
	ops[0x7].accepted_args[2] = T_REG;
	ops[0x8].accepted_args[2] = 0;
	ops[0x9].accepted_args[2] = T_REG;
	ops[0xa].accepted_args[2] = T_DIR | T_REG;
	ops[0xb].accepted_args[2] = 0;
	ops[0xc].accepted_args[2] = 0;
	ops[0xd].accepted_args[2] = T_REG;
	ops[0xe].accepted_args[2] = 0;
	ops[0xf].accepted_args[2] = 0;
}

void	asm_set_ops_accepted_args_2(t_op *ops)
{
	ops[0].accepted_args[1] = 0;
	ops[0x1].accepted_args[1] = T_REG;
	ops[0x2].accepted_args[1] = T_REG | T_IND;
	ops[0x3].accepted_args[1] = T_REG;
	ops[0x4].accepted_args[1] = T_REG;
	ops[0x5].accepted_args[1] = T_REG | T_DIR | T_IND;
	ops[0x6].accepted_args[1] = T_DIR | T_REG | T_IND;
	ops[0x7].accepted_args[1] = T_DIR | T_REG | T_IND;
	ops[0x8].accepted_args[1] = 0;
	ops[0x9].accepted_args[1] = T_DIR | T_REG;
	ops[0xa].accepted_args[1] = T_REG | T_DIR | T_IND;
	ops[0xb].accepted_args[1] = 0;
	ops[0xc].accepted_args[1] = T_REG;
	ops[0xd].accepted_args[1] = T_DIR | T_REG;
	ops[0xe].accepted_args[1] = 0;
	ops[0xf].accepted_args[1] = 0;
	asm_set_ops_accepted_args_3(ops);
}

void	asm_set_ops_accepted_args(t_op *ops)
{
	ops[0].accepted_args[0] = T_DIR;
	ops[0x1].accepted_args[0] = T_DIR | T_IND;
	ops[0x2].accepted_args[0] = T_REG;
	ops[0x3].accepted_args[0] = T_REG;
	ops[0x4].accepted_args[0] = T_REG;
	ops[0x5].accepted_args[0] = T_REG | T_DIR | T_IND;
	ops[0x6].accepted_args[0] = T_DIR | T_REG | T_IND;
	ops[0x7].accepted_args[0] = T_DIR | T_REG | T_IND;
	ops[0x8].accepted_args[0] = T_DIR;
	ops[0x9].accepted_args[0] = T_DIR | T_REG | T_IND;
	ops[0xa].accepted_args[0] = T_REG;
	ops[0xb].accepted_args[0] = T_DIR;
	ops[0xc].accepted_args[0] = T_DIR | T_IND;
	ops[0xd].accepted_args[0] = T_DIR | T_IND | T_REG;
	ops[0xe].accepted_args[0] = T_DIR;
	ops[0xf].accepted_args[0] = T_REG;
	asm_set_ops_accepted_args_2(ops);
}
