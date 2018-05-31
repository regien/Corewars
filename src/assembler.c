/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:00:25 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/29 15:49:09 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include <errno.h>

char	*convert_cor(char *s)
{
	char	*cor;
	int		i;

	cor = ft_strnew(ft_strlen(s) + 2);
	ft_strcpy(cor, s);
	i = 0;
	while (cor[i] && cor[i] != '.')
		i++;
	if (!cor[i])
		return (0);
	i++;
	cor[i] = 'c';
	cor[i + 1] = 'o';
	cor[i + 2] = 'r';
	cor[i + 3] = 0;
	return (cor);
}

void	free_ops_and_labels(t_ops *op, t_label *label)
{
	t_ops	*tmp;
	t_label	*aux;
	int		i;

	while (op)
	{
		i = -1;
		while (++i < op_table[op->op_code - 1].args)
			if (op->arg_name[i])
				free(op->arg_name[i]);
		free(op->arg_name);
		free(op->op_name);
		tmp = op->next;
		free(op);
		op = tmp;
	}
	while (label)
	{
		free(label->label_name);
		aux = label->next;
		free(label);
		label = aux;
	}
}

int		main(int argc, char **argv)
{
	int				fd;
	t_ops			*ops;
	t_label			*labels;
	t_header		header;
	char			*cor_name;

	asm_init_ops(op_table);
	if (argc != 2 || (argc == 2 && !ft_strchr(argv[1], '.')))
		return (ft_printf_err("Usage: ./asm name_of_file.s\n"));
	if ((fd = open(argv[1], O_RDONLY)) < 3)
		return (ft_printf_err("invalid file\n"));
	if (set_header(&header, fd))
		return (1);
	if (!(ops = set_argument_list(fd, &labels)))
		return (ft_printf_err("ERR ON FILE, maybe empty\n"));
	if (set_label_vars(labels, ops))
		return (1);
	cor_name = convert_cor(argv[1]);
	if ((fd = open(cor_name, O_WRONLY | O_TRUNC | O_CREAT, 0666)) < 3)
		return (ft_printf_err("couldn't create file\n %d\n", fd));
	write_file(fd, ops, labels, &header);
	//print_commands(ops, labels);
	while (labels)
	{
		printf("%s: %d\n", labels->label_name, labels->index);
		labels = labels->next;
	}
	free(cor_name);
	free_ops_and_labels(ops, labels);
	ft_printf("%s became .cor... magically\n", argv[1]);
	return (0);
}
