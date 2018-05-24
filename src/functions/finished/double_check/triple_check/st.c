/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:18:56 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 23:37:03 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Takes 2 paramters. It stores the first parameter's value (which is a reg)
**	into the second (both).
**	// To number:	
**	st (r4, 34) stores the content of r4 at the address PC + 34 % IND_MOD.
**	// To register:	
**	st (r3, r8) copies the content of r3 into r8.
*/

static void	store_big_endian(t_vm *vm, int value, int index)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = value & 0xff000000;
	b = value & 0x00ff0000;
	c = value & 0x0000ff00;
	d = value & 0x000000ff;
	vm.memory[index] = a;
	vm.memory[index + 1] = b;
	vm.memory[index + 2] = c;
	vm.memory[index + 3] = d;
}

void		ft_st(t_vm *vm, t_process *process)
{
	if (reg(process, 0))
	{
		if (reg(process, 1))
		{
			process.reg[process->arg.v[1] - 1] = 
				process.reg[process->arg.v[0] - 1];
		}
		else if (ind(process, 1))
		{
			store_big_endian(vm, process->arg.v[0], process->arg.v[1] % IND_MOD);
		}
	}
}
