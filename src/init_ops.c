/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 01:20:26 by adubugra          #+#    #+#             */
/*   Updated: 2018/06/01 04:27:37 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

/*
**	#DEFINE PLACE_HOLDER	ops[0x00]
**	#DEFINE LIVE			ops[0x01]
**	#DEFINE LD				ops[0x02]
**	#DEFINE ST				ops[0x03]
**	#DEFINE ADD				ops[0x04]
**	#DEFINE	SUB				ops[0x05]
**	#DEFINE AND				ops[0x06]
**	#DEFINE OR				ops[0x07]
**	#DEFINE XOR				ops[0x08]
**	#DEFINE ZJMP			ops[0x09]
**	#DEFINE LDI				ops[0x0a]
**	#DEFINE STI				ops[0x0b]
**	#DEFINE FORK			ops[0x0c]
**	#DEFINE LLD				ops[0x0d]
**	#DEFINE LLDI			ops[0x0e]
**	#DEFINE LFORK			ops[0x0f]
**	#DEFINE AFF				ops[0x10]
*/

/*
**	Truncations apply to direct (DIR) values. A normal direct size is REG_SIZE
**	(4) bytes and a truncated is two.
*/

void	set_truncate(t_op *ops)
{
	ops[0].truncate = 0;
	ops[0x1].truncate = 0;
	ops[0x2].truncate = 0;
	ops[0x3].truncate = 0;
	ops[0x4].truncate = 0;
	ops[0x5].truncate = 0;
	ops[0x6].truncate = 0;
	ops[0x7].truncate = 0;
	ops[0x8].truncate = 0;
	ops[0x9].truncate = 1;
	ops[0xa].truncate = 1;
	ops[0xb].truncate = 1;
	ops[0xc].truncate = 1;
	ops[0xd].truncate = 0;
	ops[0xe].truncate = 1;
	ops[0xf].truncate = 1;
	ops[0x10].truncate = 0;
}

/*
**	Acb also known as Access method Control Block is a discriptor of the
**	parameters following the operation execution code. In binary, it is an
**	octect containing potentially up to 3 parameters (max) and described in 
**	duplets. 01 is the code for register (1 byte), 10 is the code for direct
**	(2 or 4 bytes) and 11 is the code for indirect (2 bytes).
**	Eg: An opcode consisting of 01 10 11 00 for size of char contains
**	a register for the first parameter, a direct for the second, and
**	An indirect for the last. The following is an initilization whether or not
**	an encoding byte (acb) exists for the following operations.
*/

void	set_ops_acb(t_op *ops)
{
	ops[0].descriptor= 0;
	ops[0x1].descriptor = 0;
	ops[0x2].descriptor = 1;
	ops[0x3].descriptor = 1;
	ops[0x4].descriptor = 1;
	ops[0x5].descriptor = 1;
	ops[0x6].descriptor = 1;
	ops[0x7].descriptor = 1;
	ops[0x8].descriptor = 1;
	ops[0x9].descriptor = 0;
	ops[0xa].descriptor = 1;
	ops[0xb].descriptor = 1;
	ops[0xc].descriptor = 0;
	ops[0xd].descriptor = 1;
	ops[0xe].descriptor = 1;
	ops[0xf].descriptor = 0;
	ops[0x10].descriptor = 1;
	set_truncate(ops);
}

/*
**	The following is the amount of cycles it takes for each operaration needed
**	to wait before execution.
*/

void	set_ops_cycles(t_op *ops)
{
	ops[0].cycles = 0;
	ops[0x1].cycles = 10;
	ops[0x2].cycles = 5;
	ops[0x3].cycles = 5;
	ops[0x4].cycles = 10;
	ops[0x5].cycles = 10;
	ops[0x6].cycles = 6;
	ops[0x7].cycles = 6;
	ops[0x8].cycles = 6;
	ops[0x9].cycles = 20;
	ops[0xa].cycles = 25;
	ops[0xb].cycles = 25;
	ops[0xc].cycles = 800;
	ops[0xd].cycles = 10;
	ops[0xe].cycles = 50;
	ops[0xf].cycles = 1000;
	ops[0x10].cycles = 2;
	set_ops_acb(ops);
}

/*
**	Below is the declaration of the number of arguments each operation takes in.
*/

void	set_ops_args(t_op *ops)
{
	ops[0].args = 0;
	ops[0x1].args = 1;
	ops[0x2].args = 2;
	ops[0x3].args = 2;
	ops[0x4].args = 3;
	ops[0x5].args = 3;
	ops[0x6].args = 3;
	ops[0x7].args = 3;
	ops[0x8].args = 3;
	ops[0x9].args = 1;
	ops[0xa].args = 3;
	ops[0xb].args = 3;
	ops[0xc].args = 1;
	ops[0xd].args = 2;
	ops[0xe].args = 3;
	ops[0xf].args = 1;
	ops[0x10].args = 1;
	set_ops_cycles(ops);
}

/*
**	Function pointers in C. I'm sure you know what those are ;)
*/

void	init_ops(t_op *ops)
{
	ops[0x1].func_to_be = &ft_live;
	ops[0x2].func_to_be = &ft_ld;
	ops[0x3].func_to_be = &ft_st;
	ops[0x4].func_to_be = &ft_add;
	ops[0x5].func_to_be = &ft_sub;
	ops[0x6].func_to_be = &ft_and;
	ops[0x7].func_to_be = &ft_or;
	ops[0x8].func_to_be = &ft_xor;
	ops[0x9].func_to_be = &ft_zjmp;
	ops[0xa].func_to_be = &ft_ldi;
	ops[0xb].func_to_be = &ft_sti;
	ops[0xc].func_to_be = &ft_fork;
	ops[0xd].func_to_be = &ft_lld;
	ops[0xe].func_to_be = &ft_lldi;
	ops[0xf].func_to_be = &ft_lfork;
	ops[0x10].func_to_be = &ft_aff;
	set_ops_args(ops);
}
