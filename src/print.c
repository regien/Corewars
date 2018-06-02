/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 01:17:30 by adubugra          #+#    #+#             */
/*   Updated: 2018/06/01 04:52:23 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void	init_colors(t_vm vm)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		vm.mem_color[i] = 0;
		i++;
	}
}

void	dump_memory_wrapper(t_vm vm)
{
	dump_memory(vm);
	exit(0);
}
/*
void	dump_memory(t_vm vm)
{
	int		i;
	char	*mem;

	mem = vm.memory;
	i = 0;
	init_colors(vm);
	while (i < MEM_SIZE)
	{
		if ((i % 64 == 0)) // printing 64 chars at a time per line
			ft_putchar('\n');


		if (vm.mem_color[i] == -1)
			printf(RED "%s ", ft_ctoa_base(mem[i], 16));
		else if (vm.mem_color[i] == -2)
			printf(GRN "%s ", ft_ctoa_base(mem[i], 16));
		else if (vm.mem_color[i] == -3)
			printf(BLU "%s ", ft_ctoa_base(mem[i], 16));
		else if (vm.mem_color[i] == -4)
			printf(MAG"%s ", ft_ctoa_base(mem[i], 16));
		else
			printf("%s ", ft_ctoa_base(mem[i], 16));
		i++;
	}
	ft_putchar('\n');
}
*/
void	dump_memory(t_vm vm)
{
	int		i;
	char	*mem;

	mem = vm.memory;
	i = 0;
	while (i < MEM_SIZE)
	{
		if ((i % 64 == 0)) // printing 64 chars at a time per line
			ft_putchar('\n');
		ft_printf("%s ", ft_ctoa_base(mem[i], 16));
		i++;
	}
	ft_putchar('\n');
}

