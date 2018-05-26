/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_name_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:41:43 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/25 16:13:22 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

char	*find_line(char *cmd_string, int fd)
{
	char	*str;
	char	*tmp;
	int		ret;

	while ((ret = get_next_line(fd, &str)) == 1)
		if ((tmp = ft_strstr(str, cmd_string)) == 0)
			free(str);
		else
			break ;
	if (!tmp)
		return (0);
	return (str);
}

int		set_name(char name[PROG_NAME_LENGTH + 5], int fd)
{
	char	*str;
	int		i;
	int		j;
	char	*tmp;

	if ((str = find_line(NAME_CMD_STRING, fd)) == 0)
		return (ft_printf("ERR at name: couldn't find name\n"));
	if ((tmp = ft_strstr(str, NAME_CMD_STRING)) == 0)
		return (ft_printf("ERR at name: no %s\n", NAME_CMD_STRING));
	i = 0;
	while (&str[i] != tmp)
		i++;
	while (str[i] && str[i] != 34)
		i++;
	if (!(str[i]))
		return (ft_printf("ERR at name, missing quotes %d\n", i));
	i++;
	j = 0;
	while (str[i] && str[i] != 34 && j <= PROG_NAME_LENGTH)
		name[j++] = str[i++];
	if (!str[i] || j > PROG_NAME_LENGTH)
		return (ft_printf("ERR at name, name too big\n"));
	free(str);
	return (0);
}

int		set_comment(char comment[COMMENT_LENGTH + 5], int fd)
{
	char	*str;
	int		i;
	int		j;
	char	*tmp;

	if ((str = find_line(COMMENT_CMD_STRING, fd)) == 0)
		return (ft_printf("ERR at comment: couldn't find comment\n"));
	if ((tmp = ft_strstr(str, COMMENT_CMD_STRING)) == 0)
		return (ft_printf("ERR at comment: no %s\n", COMMENT_CMD_STRING));
	i = 0;
	while (&str[i] != tmp)
		i++;
	while (str[i] && str[i] != 34)
		i++;
	if (!(str[i]))
		return (ft_printf("ERR at comment, missing quotes %d\n", i));
	i++;
	j = 0;
	while (str[i] && str[i] != 34 && j <= COMMENT_LENGTH)
		comment[j++] = str[i++];
	if (!str[i] || j > COMMENT_LENGTH)
		return (ft_printf("ERR at comment, comment too big\n"));
	free(str);
	return (0);
}

int		set_header(t_header *h, int fd)
{
	int i;

	i = -1;
	while (++i <= COMMENT_LENGTH + 4)
		h->prog_name[i] = 0;
	if (set_name(h->prog_name, fd))
		return (1);
	i = -1;
	while (++i <= COMMENT_LENGTH + 4)
		h->comment[i] = 0;
	if (set_comment(h->comment, fd))
		return (1);
	return (0);
}
