/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_and_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:16:17 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/31 07:03:56 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


//void		get_type(t_command_args *arg, char octet)
void		get_type(t_command_args *arg, unsigned char octet)
{
	printf("value of octect to get TYPE FROM : %d\n", octet);
	arg->type[0] = (octet >> 6) & 3;
	printf("GET_TYPE of arg 0 is %d", arg->type[0]);
	arg->type[1] = (octet >> 4) & 3;
	arg->type[2] = (octet >> 2) & 3;
}



void	execute(t_vm *vm, t_process *p)
{
	int		i;
	int		curr_op;

	curr_op = p->curr_op;
	if (g_ops[curr_op].descriptor)
		get_type(&(p->arg), (unsigned char)p->pc[circulate_index(p->index + 1)]);

//		get_type(&(p->arg), p->pc[circulate_index(p->index)]);
//	set_index(&(p->index), g_ops[curr_op].descriptor ? 1 : 0);
//	set_index(&(p->index), 100);
	// moving the cursor if ACB exist 
	g_ops[curr_op].func_to_be(vm, p->father_champ, p);



	i = -1;
	p->arg.args_size = 0;
	if (g_ops[p->curr_op].descriptor == 1)
		while (++i < g_ops[p->curr_op].args)
		{
			p->arg.args_size += find_arg_size(p, i);
			printf("ARGS_SIZE OF |%d| PARAMETER  = SIZE OF |%d|", i, p->arg.args_size);
		}
	else
		if (p->curr_op == 1)
			p->arg.args_size += 4;
		else
			p->arg.args_size += 3;
	if (curr_op != 9)
		set_index(&(p->index), p->arg.args_size + \
			(g_ops[curr_op].descriptor ? 1 : 0) + 1);
	printf("MOD THE INDEX BY : |%d|\n", p->arg.args_size + \
		(g_ops[curr_op].descriptor ? 1 : 0) + 1);
	// we are setting the arg.size inside the function
//	dump_memory(*vm); // <_ HERE _ DUMP _ MEMORY
// end working area	}
	printf("index: %d\n", p->index);
	//modify index here
//	set_index(&(p->index), );
	p->curr_op = 0;
	//dump_memory(*vm); DONT REMOVE THIS DEBUG STATEMENT
}


void	fetch(t_process *process)
{
	if (process->pc[process->index] <= 16 && process->pc[process->index] > 0)
	{
		process->curr_op = process->pc[process->index];
		process->cycle_counter = g_ops[process->curr_op].cycles + 1;
	}
	else
	{
		process->curr_op = 0;
		process->cycle_counter = 0;
	}
	if (process->curr_op == 0)
	{
//		printf("process->index : %d\n", process->index);
		set_index(&(process->index), 1); // review this
	}
	//setting the index in the ACB
}
