/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 01:05:08 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/30 21:27:33 by gmalpart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		check_magic_number(int fd)
{
	unsigned int	magic_nbr;

	read(fd, &magic_nbr, sizeof(unsigned int));
	convert_big_endian(&magic_nbr);
	if (magic_nbr != COREWAR_EXEC_MAGIC)
	{
		ft_putstr_fd("file not valid... no magic number\n", 2);
		return (1);
	}
	return (0);
}

void	set_index(int *index, int diff)
{
	*index += diff;
	while (*index >= MEM_SIZE)
		*index -= MEM_SIZE;
}
