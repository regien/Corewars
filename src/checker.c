/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 01:05:08 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/26 19:26:59 by gmalpart         ###   ########.fr       */
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

/*
** set_index replacer
** replacer:  index_modification
*/

int			index_mod(int index, int diff)
{
	int		new_index;

	index += diff;
	if (index >= MEM_SIZE)
		while (index >= MEM_SIZE)
			index -= MEM_SIZE;
	else
		while (index <= MEM_SIZE)
			index += MEM_SIZE;
	new_index = index;
	return (new_index);
}

