/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_op_builder_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:52:09 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/24 21:55:56 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	remove_comments(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != COMMENT_CHAR)
		i++;
	if (str[i] == COMMENT_CHAR)
	{
		while (str[i])
		{
			str[i] = ' ';
			i++;
		}
	}
}

int		check_argument(char *str)
{
	int	i;

	if (str[0] != 'r' && str[0] != DIRECT_CHAR &&
			str[0] != LABEL_CHAR && !ft_isdigit_sign(str[0]))
		return (ft_printf("err on char %c\n", str[0]));
	if ((str[0] == 'r' || str[0] == DIRECT_CHAR) && !str[1])
		return (ft_printf("err: missing number\n"));
	if (str[0] == 'r' && str[1] == LABEL_CHAR)
		return (ft_printf("registers don't take labels!\n"));
	if (str[0] == LABEL_CHAR || str[1] == LABEL_CHAR)
		return (0);
	i = 1;
	while (str[++i] && str[1] != LABEL_CHAR)
		if (!ft_isdigit_sign(str[i]))
			return (ft_printf("err on char %c\n", str[i]));
	return (0);

}

int		convert_b_endian(unsigned int num)
{
	num =	(((num)>>24)&0xff) | // move byte 3 to byte 0
			(((num)<<8)&0xff0000) | // move byte 1 to byte 2
			(((num)>>8)&0xff00) | // move byte 2 to byte 1
			(((num)<<24)&0xff000000); // byte 0 to byte 3
	return (num);
}

int		convert_b_endian_short(unsigned short num)
{
	num =	((num)<<8 | (num)>>8); // move byte 2 to byte 1
	return (num);
}
