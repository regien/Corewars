/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:00:20 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/17 01:54:06 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	controller(t_vm *vm)
{
	int		i;

		i = 0;
		//while (i < vm->players)
		//{
			fetch(vm->champs[i].processes);
			fetch(vm->champs[i].processes);
			fetch(vm->champs[i].processes);
			fetch(vm->champs[i].processes);
			/*
			for each process in each hero
				if (process.state == WAIT)
					process.counter--
					if (process.counter == 0)
						process.state = EXEC
				if (process.state == fetch)
					process.func = fetch_next(PC pointer);
					process.cycle_counter = func_respective_cycles - 1
					process.state == WAiT
				if (process.state == EXEC)
					execute(process.func(args))
					move PC pointer*/
			i++;
		//}
		vm->cycles++;
}

char	get_type(char octet, char arg_num)
{
	printf("octet %hhd\n", octet);
	if (octet >> (9 - 2 * arg_num) & 1 && octet >> (8 - 2 * arg_num) & 1)
		return (IND_CODE);
	if (octet >> (9 - 2 * arg_num) & 1 && !(octet >> (8 - 2 * arg_num) & 1))
		return (DIR_CODE);
	if (!(octet >> (9 - 2 * arg_num) & 1) && octet >> (8 - 2 * arg_num) & 1)
		return (REG_CODE);
	ft_printf("Code not recognized\n");
	return (0);
}

size_t	set_arg(char **pc, char type, int *value, char truncation)
{
	char	*c;
	short	*s;
	int		*i;

		printf("pc: %d\n", **pc);
		printf("pc + 1: %d\n", *(*pc + 1));
		printf("pc + 2: %d\n", *(*pc + 2));
	if (type == IND_CODE || (type == DIR_CODE && truncation))
	{
		s = (short *)(*pc);
		*value = *s;
		convert_big_endian_short((unsigned short *)value);
		*pc += 2;
		return (2);
	}
	else if (type == REG_CODE)
	{
		c = (*pc);
		*value = *c;
		*pc += 1;
		return (1);
	}
	if (type == DIR_CODE && !truncation)
	{
		i = (int *)(*pc);
		*value = *i;
		convert_big_endian((unsigned int *)value);
		*pc += 4;
		return (4);
	}
	ft_printf("no type\n");
	return (0);
}

void	fetch(t_process *process)
{
	//get which command;
	//get arg types;
	//get args;
	char type;
	int		i;
	int		curr_op;

	if (*(process->pc) < 17 && *(process->pc) > 0)
	{
		curr_op = *(process->pc);
		process->ops[1].func_to_be("SENT IT BOLUDO!\n");
	printf("ate aqui ok \n");
		process->pc += 1;
		type = *(process->pc);
		i = -1;
		while (++i < process->ops[curr_op].args)
			if (process->ops[curr_op].descriptor)
				process->arg.type[i] = get_type(type, i + 1);
			else
				process->arg.type[i] = DIR_CODE;
		process->pc += process->ops[curr_op].descriptor ? 1 : 0;
		process->arg.args_size = 0;
		i = -1;
		while (++i < process->ops[curr_op].args)
			process->arg.args_size += set_arg(&(process->pc),
			process->arg.type[i], &(process->arg.v[i]), process->ops[curr_op].truncate);
		ft_printf("v: %hd\n", process->arg.v[0]);
		ft_printf("v2: %hd\n", process->arg.v[1]);
		ft_printf("v3: %hd\n", process->arg.v[2]);
	}
	else
		process->pc += 1;
	//ft_printf("size: %d\n", process->arg.args_size);
	//proces->func_to_be = get_func(pc);

}













