/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 15:00:20 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/17 18:18:11 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"
#define PROCESS vm->champs[i].processes

void	controller(t_vm *vm)
{
	int		i;

		i = 0;
		while (1)
		{
			i = 0;
			while (i < vm->players)
			{
				if (PROCESS->curr_op == 0)
				{
					fetch(PROCESS);
					printf("champs %d fetched op %d\n", i + 1, vm->champs[i].processes->curr_op);
				}
				if (PROCESS->cycle_counter == 0 &&
						PROCESS->curr_op)
				{
					execute(PROCESS);
					printf("champs %d executed op %d\n", i + 1, PROCESS->curr_op);
				}
				else if (PROCESS->cycle_counter > 0)
				{
					printf("champs %d has %d cycles before executing\n", i + 1, PROCESS->cycle_counter);
					PROCESS->cycle_counter--;
				}
				i++;
			}
			vm->cycles++;
			printf("vm cycles: %d\n", vm->cycles);
			if (vm->cycles >= 2*1140)
				break ;
		}
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

void	execute(t_process *process)
{
	//get which command;
	//get arg types;
	//get args;
	char type;
	int		i;
	int		curr_op;

	curr_op = process->curr_op;
				printf("curr_op: %d\n", process->curr_op);
	type = *(process->pc);
	i = -1;
	while (++i < process->ops[curr_op].args)
		if (process->ops[curr_op].descriptor)
			process->arg.type[i] = get_type(*(process->pc), i + 1);
		else
			process->arg.type[i] = DIR_CODE;
	process->pc += process->ops[curr_op].descriptor ? 1 : 0;
	process->arg.args_size = 0;
	i = -1;
	while (++i < process->ops[curr_op].args)
		process->arg.args_size += set_arg(&(process->pc),
		process->arg.type[i], &(process->arg.v[i]), process->ops[curr_op].truncate);
	printf("curr_op %d\n", curr_op);
	process->ops[curr_op].func_to_be("VAIII DANADA %d\n", curr_op);
	process->curr_op = 0;
}

void	fetch(t_process *process)
{
	if (*(process->pc) <= 16 && *(process->pc) > 0)
	{
		process->curr_op = *(process->pc);
		process->cycle_counter = process->ops[process->curr_op].cycles;
	}
	else
	{
		process->curr_op = 0;
		process->cycle_counter = 0;
	}
	process->pc += 1;
}
