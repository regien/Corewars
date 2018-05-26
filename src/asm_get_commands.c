/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:58:56 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/25 20:11:28 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

char		*get_full_line(int fd)
{
	char	*str;
	char	*tmp;
	int		i;

	while (get_next_line(fd, &str) >= 0)
	{
		remove_comments(str);
		tmp = str;
		if (!str)
			break ;
		i = 0;
		while (str[i] && WHITESPACE(str[i]))
			i++;
		str = str[i] == 0 ? 0 : str;
		if (str == 0)
			free(tmp);
		else
			break ;
	}
	if (str)
	{
		free(tmp);
		return (ft_strdup(&str[i]));
	}
	return (str);
}

int			check_label_name(t_label *label)
{
	char	*str;
	int		i;

	str = label->label_name;
	i = 0;
	while (str[i])
	{
		if (!ft_strchr(LABEL_CHARS, str[i]) && str[i] != LABEL_CHAR)
			return (ft_printf_err("Invalid Label %s\n", label->label_name));
		i++;
	}
	return (0);
}

t_label		*get_label(char **full_str)
{
	int		i;
	t_label	*new_label;
	char	*str;

	i = 0;
	str = *full_str;
	while (!WHITESPACE(str[i]) && str[i] && str[i] != LABEL_CHAR)
		i++;
	if (str[i] != LABEL_CHAR)
		return (0);
	new_label = init_label();
	new_label->label_name = ft_strsub(str, 0, (size_t)i + 1);
	if (check_label_name(new_label))
		return (0);
	*full_str = &str[i + 1];
	while (**full_str && WHITESPACE(**full_str))
		(*full_str)++;
	if (**full_str == 0)
		*full_str = 0;
	return (new_label);
}

/*
**returns the list with all the ops and labels created
*/

t_ops		*set_argument_list(int fd, t_label **label_root)
{
	t_ops	*root;
	t_ops	*last;
	t_label	*buf;
	char	*str;
	char	*tmp;

	*label_root = 0;
	last = 0;
	root = 0;
	while ((str = get_full_line(fd)) != 0)
	{
		tmp = str;
		buf = add_label(label_root, get_label(&str));
		if (!str)
			continue ;
		if (!add_ops(&root, &last, str))
			return (0);
		free(tmp);
		if (buf)
			buf->index = last->index;
	}
	return (root);
}
