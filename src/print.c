/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 01:17:30 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/16 01:51:53 by adubugra         ###   ########.fr       */
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
		ft_printf("%s ", ft_ctoa_base(mem[i], 16));
		if (i % 16 == 0 || i == MEM_SIZE - 1)
			ft_putchar('\n');
		i++;
	}
}
