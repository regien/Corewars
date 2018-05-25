/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 00:50:02 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/24 21:26:01 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	convert_big_endian(unsigned int *num)
{
	*num =	(((*num)>>24)&0xff) | // move byte 3 to byte 0
			(((*num)<<8)&0xff0000) | // move byte 1 to byte 2
			(((*num)>>8)&0xff00) | // move byte 2 to byte 1
			(((*num)<<24)&0xff000000); // byte 0 to byte 3
}

void	convert_big_endian_short(unsigned short *num)
{
	*num =	((*num)<<8 | (*num)>>8); // move byte 2 to byte 1
}
