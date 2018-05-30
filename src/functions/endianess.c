/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endianess.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 23:46:48 by eliu              #+#    #+#             */
/*   Updated: 2018/05/29 23:46:53 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_4_bytes(t_vm *vm, t_process *process, int index, int i)
{
	ft_putendl("	arg is an indirect: entered read_4_bytes");
	process->arg.v[i] = (vm->memory[circulate_index(index)] & 0xFF) << 24;
	process->arg.v[i] += (vm->memory[circulate_index(index + 1)] & 0xFF) << 16;
	process->arg.v[i] += (vm->memory[circulate_index(index + 2)] & 0xFF) << 8;
	process->arg.v[i] += (vm->memory[circulate_index(index + 3)] & 0xFF);
	ft_putendl("	exited read_4_bytes");
}

void 	read_2_bytes(t_vm *vm, t_process *process, int index, int i)
{
	printf("	arg is an indirect: entered read_2_bytes index = %d\n", index);
	process->arg.v[i] = vm->memory[circulate_index(index)];
	process->arg.v[i] = (process->arg.v[i] & 0xFF) << 8; //cast to char
	process->arg.v[i] += vm->memory[circulate_index(index + 1)] & 0xFF;
	printf("i value = %d shift = %d\n", i, process->arg.v[i]);
	ft_putendl("	exited read_2_bytes");
}

void	store_big_endian(t_vm *vm, int value, int index)
{
	ft_putendl("	entered big endian");
	unsigned char	a;
	unsigned char	b;
	unsigned char	c;
	unsigned char	d;

	a = (value & 0xff000000) >> 24;
	b = (value & 0x00ff0000) >> 16;
	c = (value & 0x0000ff00) >> 8;
	d = value & 0x000000ff;
	vm->memory[circulate_index(index)] = a;
	vm->memory[circulate_index(index + 1)] = b;
	vm->memory[circulate_index(index + 2)] = c;
	vm->memory[circulate_index(index + 3)] = d;
	ft_putendl("	store big endian");
}
