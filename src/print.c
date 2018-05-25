/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 01:17:30 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/24 20:52:56 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	dump_memory(t_vm vm)
{
	int		i;
	char	*mem;

	mem = vm.memory;
	i = 0;
	while (i < MEM_SIZE)
	{
//		if ((i % 16 == 0))
		if ((i % 64 == 0)) // printing 64 chars at a time per line
			ft_putchar('\n');
		ft_printf("%s ", ft_ctoa_base(mem[i], 16));
//
		i++;
	}
	ft_putchar('\n');
}
