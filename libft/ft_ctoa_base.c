/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 01:31:04 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/16 01:50:35 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	equiv(int n)
{
	if (n >= 0 && n <= 9)
		return (n + 48);
	else if (n >= 10 && n <= 15)
		return (n + 87);
	else
		return (40);
}

static int	size(int n, int base)
{
	int counter;

	counter = 0;
	while (n != 0)
	{
		n /= base;
		counter++;
	}
	return (counter);
}

char		*ft_ctoa_base(unsigned char v, int base)
{
	char	*ctoa;
	int		value;
	int		len;
	int		i;

	value = v;
	len = size(value, base);
	if (value <= 0)
		len++;
	if (len == 1)
	{
		len++;
		ctoa = ft_strnew(len);
		ctoa[0] = '0';
	}
	else
		ctoa = ft_strnew(len);
	if (value < 0)
	{
		ctoa[0] = 'f';
		value *= -1;
	}
	i = 1;
	if (value == 0)
		ctoa[1] = '0';
	while (value > 0)
	{
		ctoa[len - i] = equiv(value % base);
		value /= base;
		i++;
	}
	return (ctoa);
}
