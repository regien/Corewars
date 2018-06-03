/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endianess.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 23:46:48 by eliu              #+#    #+#             */
/*   Updated: 2018/06/02 21:59:52 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		circulate_index(int index)
{
//	printf("Index before entering circulate: %d\n", index);
	while (index < 0)
	{
		index = index + MEM_SIZE;
	}
	while (index >= MEM_SIZE)
	{
		index = index - MEM_SIZE;
	}
//	printf("Index after exiting circulate: %d\n", index);
	return (index);
}

void	read_4_bytes(t_vm *vm, t_process *process, int index, int i)
{
	printf("index we are reading from is: |%d|\n", index);
	process->arg.v[i] = (vm->memory[circulate_index(index)] & 0xFF) << 24;
	process->arg.v[i] += (vm->memory[circulate_index(index + 1)] & 0xFF) << 16;
	process->arg.v[i] += (vm->memory[circulate_index(index + 2)] & 0xFF) << 8;
	process->arg.v[i] += (vm->memory[circulate_index(index + 3)] & 0xFF);
	printf("4 bytes read is: |%d|\n", process->arg.v[i]);
	//print_big_endian(process->arg.v[i]);
}

void 	read_2_bytes(t_vm *vm, t_process *process, int index, int i)
{
	printf("index we are reading from is: |%d|\n", index);
	process->arg.v[i] = vm->memory[circulate_index(index)];
	process->arg.v[i] = (process->arg.v[i] & 0xFF) << 8; //cast to char
	process->arg.v[i] += vm->memory[circulate_index(index + 1)] & 0xFF;
	process->arg.v[i] = (short)(process->arg.v[i]);
	printf("arg.v[%d] is : |%d|\n", i, process->arg.v[i]);
}

void	print_big_endian(int x)
{
	printf("print big endian |%x| |%x| |%x| |%x|\n", (x << 24) & 0xff000000, (x << 16) & 0xff0000,
		(x << 8) & 0xff00, x & 0xff);
}

void	store_big_endian(t_vm *vm, int value, int index)
{
	char	a;
	char	b;
	char	c;
	char	d;

	printf("\nStoring index starting at: |%d|\n", index);
	a = (value & 0xff000000) >> 24;
	b = (value & 0x00ff0000) >> 16;
	c = (value & 0x0000ff00) >> 8;
	d = value & 0x000000ff;

	vm->memory[circulate_index(index)] = a;
	vm->memory[circulate_index(index + 1)] = b;
	vm->memory[circulate_index(index + 2)] = c;
	vm->memory[circulate_index(index + 3)] = d;
	
	
	printf("value of a = |%d| value of b = |%d| value of c = |%d| value of d = %d\n", vm->memory[circulate_index(index)], vm->memory[circulate_index(index + 1)], vm->memory[circulate_index(index + 2)], vm->memory[circulate_index(index + 3)]);
}
