/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_op_builder_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:52:09 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/25 19:47:24 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	remove_comments(char *str)
{
	int i;

	if (!str)
		return ;
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
		return (ft_printf_err("err on char %c\n", str[0]));
	if ((str[0] == 'r' || str[0] == DIRECT_CHAR) && !str[1])
		return (ft_printf_err("err: missing number\n"));
	if (str[0] == 'r' && str[1] == LABEL_CHAR)
		return (ft_printf_err("registers don't take labels!\n"));
	if (str[0] == LABEL_CHAR || str[1] == LABEL_CHAR)
		return (0);
	i = 1;
	while (str[++i] && str[1] != LABEL_CHAR)
		if (!ft_isdigit_sign(str[i]) || str[i] == 'x')
			return (ft_printf_err("err on char %c\n", str[i]));
	return (0);
}

int		convert_b_endian(unsigned int num)
{
	num = (((num) >> 24) & 0xff) |
			(((num) << 8) & 0xff0000) |
			(((num) >> 8) & 0xff00) |
			(((num) << 24) & 0xff000000);
	return (num);
}

int		convert_b_endian_short(unsigned short num)
{
	num = ((num) << 8 | (num) >> 8);
	return (num);
}
