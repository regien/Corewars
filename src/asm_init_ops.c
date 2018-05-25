/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_init_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:02:18 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/24 15:50:50 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	asm_set_ops_cycles(t_op *ops)
{
	ops[0x0].cycles = 10;
	ops[0x1].cycles = 5;
	ops[0x2].cycles = 5;
	ops[0x3].cycles = 10;
	ops[0x4].cycles = 10;
	ops[0x5].cycles = 6;
	ops[0x6].cycles = 6;
	ops[0x7].cycles = 6;
	ops[0x8].cycles = 20;
	ops[0x9].cycles = 25;
	ops[0xa].cycles = 25;
	ops[0xb].cycles = 800;
	ops[0xc].cycles = 10;
	ops[0xd].cycles = 50;
	ops[0xe].cycles = 1000;
	ops[0xf].cycles = 2;
	asm_set_ops_accepted_args(ops);
}

void	asm_set_ops_descriptor(t_op *ops)
{
	ops[0x0].descriptor = 0;
	ops[0x1].descriptor = 1;
	ops[0x2].descriptor = 1;
	ops[0x3].descriptor = 1;
	ops[0x4].descriptor = 1;
	ops[0x5].descriptor = 1;
	ops[0x6].descriptor = 1;
	ops[0x7].descriptor = 1;
	ops[0x8].descriptor = 0;
	ops[0x9].descriptor = 1;
	ops[0xa].descriptor = 1;
	ops[0xb].descriptor = 0;
	ops[0xc].descriptor = 1;
	ops[0xd].descriptor = 1;
	ops[0xe].descriptor = 0;
	ops[0xf].descriptor = 1;
	asm_set_ops_cycles(ops);
}

void	asm_set_ops_args(t_op *ops)
{
	ops[0x0].args = 1;
	ops[0x1].args = 2;
	ops[0x2].args = 2;
	ops[0x3].args = 3;
	ops[0x4].args = 3;
	ops[0x5].args = 3;
	ops[0x6].args = 3;
	ops[0x7].args = 3;
	ops[0x8].args = 1;
	ops[0x9].args = 3;
	ops[0xa].args = 3;
	ops[0xb].args = 1;
	ops[0xc].args = 2;
	ops[0xd].args = 3;
	ops[0xe].args = 1;
	ops[0xf].args = 1;
	asm_set_ops_descriptor(ops);
}

void	asm_set_truncate(t_op *ops)
{
	ops[0x0].truncate = 0;
	ops[0x1].truncate = 0;
	ops[0x2].truncate = 0;
	ops[0x3].truncate = 0;
	ops[0x4].truncate = 0;
	ops[0x5].truncate = 0;
	ops[0x6].truncate = 0;
	ops[0x7].truncate = 0;
	ops[0x8].truncate = 1;
	ops[0x9].truncate = 1;
	ops[0xa].truncate = 1;
	ops[0xb].truncate = 1;
	ops[0xc].truncate = 0;
	ops[0xd].truncate = 1;
	ops[0xe].truncate = 1;
	ops[0xf].truncate = 1;
	asm_set_ops_args(ops);
}

void	asm_init_ops(t_op *ops)
{
	ops[0].op_code = 1;
	ops[0x1].op_code = 2;
	ops[0x2].op_code = 3;
	ops[0x3].op_code = 4;
	ops[0x4].op_code = 5;
	ops[0x5].op_code = 6;
	ops[0x6].op_code = 7;
	ops[0x7].op_code = 8;
	ops[0x8].op_code = 9;
	ops[0x9].op_code = 10;
	ops[0xa].op_code = 11;
	ops[0xb].op_code = 12;
	ops[0xc].op_code = 13;
	ops[0xd].op_code = 14;
	ops[0xe].op_code = 15;
	ops[0xf].op_code = 16;
	asm_set_truncate(ops);
}
