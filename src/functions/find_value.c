/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 23:35:02 by eliu              #+#    #+#             */
/*   Updated: 2018/05/28 07:24:13 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_4_bytes(t_vm *vm, t_process *process, int index, int i)
{
	ft_putendl("	arg is an indirect: entered read_4_bytes");
	process->arg.v[i] = (vm->memory[index % MEM_SIZE] & 0xFF) << 24;
	process->arg.v[i] += (vm->memory[(index + 1) % MEM_SIZE] & 0xFF) << 16;
	process->arg.v[i] += (vm->memory[(index + 2) % MEM_SIZE] & 0xFF) << 8;
	process->arg.v[i] += (vm->memory[(index + 3) % MEM_SIZE] & 0xFF);
	ft_putendl("	exited read_4_bytes");
}

void 	read_2_bytes(t_vm *vm, t_process *process, int index, int i)
{
	printf("	arg is an indirect: entered read_2_bytes index = %d\n", index);
	process->arg.v[i] = vm->memory[(index) % MEM_SIZE];
	process->arg.v[i] = (process->arg.v[i] & 0xFF) << 8; //cast to char
	process->arg.v[i] += vm->memory[(index + 1) % MEM_SIZE] & 0xFF;
	printf("i value = %d shift = %d\n", i, process->arg.v[i]);
	ft_putendl("	exited read_2_bytes");
}

void	find_direct(t_vm *vm, t_process *process, int index, int i)
{
	if (g_ops[process->curr_op].truncate == 1)
	{
		read_2_bytes(vm, process, index, i);
	}
	else 
	{
		read_4_bytes(vm, process, index, i);
	}
}

void	find_register(t_vm *vm, t_process *process, int index, int i)
{
	int register_number;

	register_number = vm->memory[index];
	// find register number;
	//if ((0 < register_number && register_number <= REG_NUMBER))
	process->arg.v[i] = register_number;
	// store register value;
	printf("arg v[%d] is :%d\n", i, process->arg.v[i]);
}

int 	find_arg_size(t_process *process, int i)
{
	if (process->arg.type[i] == 1)
	{
		return (1);
	}
	else if (process->arg.type[i] == 2)
	{
		if (g_ops[process->curr_op].truncate == 1)
		{
			return (2);
		}
		else
		{
			return (4);
		}
	}
	if (process->arg.type[i] == 3)
	{
		return (2);
	}
	return (0);
}

void	find_value(t_vm *vm, t_process *process, int jndex, char type, int param)
{
	int i;

	i = 0;
	if (type == 1)
	{
		find_register(vm, process, jndex, param);
	}
	else if (type == 2)
	{
		find_direct(vm, process, jndex, param);
	}
	else if (type == 3)
	{
		read_2_bytes(vm, process,  jndex, param);
	}
}

void	store_values(t_vm *vm, t_process *process, int jndex, int argc)
{
	int i;

	i = 0;
	while (argc != 0)
	{
		find_value(vm, process, jndex, process->arg.type[i], i);
		printf("stored values:\n process->arg.v[%d] = %d\n\n\n", i, process->arg.v[i]);
		jndex += find_arg_size(process, i);
		argc--;
		i++;
	}
}

void	print_regs(int a[])
{
	int i = 0;
	while (i <= 16)
	{
		printf("value of register %d is : %d\n", i, a[i]);
		i++;
	}


}	

void	dummy_testing(t_vm *vm)
{
	//ft_and testing
	//0000 0000
	//0101 0100 
	//st.c
	//
	//pc -> memory[0];
	vm->memory[1] = 0xA8;
	vm->memory[2] = 2;
	vm->memory[3] = 3;
	vm->memory[4] = 4;
	vm->memory[5] = 5;
	vm->memory[6] = 6;
	vm->processes->arg.type[0] = 2;
	vm->processes->arg.type[1] = 2;
	vm->processes->arg.type[2] = 1;
	vm->processes->regs[2] = 0xFF;
	vm->processes->regs[3] = 170;
	vm->processes->regs[4] = 85;
	vm->processes->regs[5] = 15;
//	vm->processes->descriptor = 1;
	vm->processes->index = 0;
	vm->processes->curr_op = 7;
	vm->processes->truncate = 1;
/*	store_values(vm, vm->processes, vm->processes->index + 1 + 1, 2);

	printf("TESTING DUMMY TESTING\n\n");
	printf("pendejada vm->processes->arg.v[0] = %d\n", vm->processes->arg.v[0]);
	printf("pendejada vm->processes->arg.v[1] = %d\n", vm->processes->arg.v[1]);
	printf("pendejada vm->processes->arg.v[2] = %d\n", vm->processes->arg.v[2]);
	printf("ENDING DUMMY TESTING\n\n");
*/
	print_regs(vm->processes->regs);
	ft_xor(vm, &(vm->champs[0]), vm->processes);
	print_regs(vm->processes->regs);
	printf("TESTING DUMMY TESTING\n\n");
	printf("pendejada vm->processes->arg.v[0] = %d\n", vm->processes->arg.v[0]);
	printf("pendejada vm->processes->arg.v[1] = %d\n", vm->processes->arg.v[1]);
	printf("pendejada vm->processes->arg.v[2] = %d\n", vm->processes->arg.v[2]);
	printf("pendejada vm->processes->arg.v[2] = %d\n", vm->processes->regs[2]);
	printf("ENDING DUMMY TESTING\n\n");
}



















