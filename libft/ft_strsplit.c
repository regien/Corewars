/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:40:32 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/25 11:02:04 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	**str2;

	if (!s || !(str2 = (char **)malloc(sizeof(*str2) *
		(ft_countwords(s, c) + 1))))
		return (NULL);
	j = 0;
	size = ft_countwords(s, c);
	i = -1;
	while (++i < size)
	{
		k = 0;
		if (!(str2[i] = ft_strnew(get_word_len(&s[j], c) + 1)))
			str2[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			str2[i][k++] = s[j++];
		str2[i][k] = '\0';
	}
	str2[i] = 0;
	return (str2);
}
