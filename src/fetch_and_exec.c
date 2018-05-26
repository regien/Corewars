/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_and_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:16:17 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/25 18:41:09 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

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

size_t	set_arg(char **pc, char type, int *value, t_process *p)
{
	char	*c;
	short	*s;
	int		*i;

	if (type == IND_CODE || (type == DIR_CODE && g_ops[p->curr_op].truncate))
	{
		s = (short *)&((*pc)[p->index]);
		*value = *s;
		convert_big_endian_short((unsigned short *)value);
		set_index(&(p->index), 2);
	}
	else if (type == REG_CODE)
	{
		c = &((*pc)[p->index]);
		*value = *c;
		set_index(&(p->index), 1);
	}
	if (type == DIR_CODE && !g_ops[p->curr_op].truncate)
	{
		i = (int *)&((*pc)[p->index]);
		*value = *i;
		convert_big_endian((unsigned int *)value);
		set_index(&(p->index), 4);
	}
	return (0);
}

void	execute(t_vm *vm, t_process *p)
{
	char type;
	int		i;
	int		curr_op;

	curr_op = p->curr_op;
	type = p->pc[p->index];
	i = -1;
	while (++i < g_ops[curr_op].args)
		if (g_ops[curr_op].descriptor)
			p->arg.type[i] = get_type(p->pc[p->index], i + 1);
		else
			p->arg.type[i] = DIR_CODE;
	set_index(&(p->index), g_ops[curr_op].descriptor ? 1 : 0);
	p->arg.args_size = 0;
	i = -1;
	while (++i < g_ops[curr_op].args)
		p->arg.args_size += set_arg(&(p->pc),
		p->arg.type[i], &(p->arg.v[i]), p);
// eliu working area {
	
	(void)vm;
	g_ops[curr_op].func_to_be(vm, p->father_champ, p);
	dump_memory(*vm);
	//	g_ops[curr_op].func_to_be("\nVAIII DANADA %d\n\n", curr_op);
	
// end working area	}
//	need to replace for the real function
	

//	g_ops[curr_op].func_to_be("\nVAIII DANADA %d\n\n", curr_op);
	printf("index: %d\n", p->index);
	p->curr_op = 0;
}

void	fetch(t_process *process)
{
	if (process->pc[process->index] <= 16 && process->pc[process->index] > 0)
	{
		process->curr_op = process->pc[process->index];
		process->cycle_counter = g_ops[process->curr_op].cycles;
	}
	else
	{
		process->curr_op = 0;
		process->cycle_counter = 0;
	}
	set_index(&(process->index), 1);
}
