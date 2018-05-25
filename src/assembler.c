/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:00:25 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/25 15:59:46 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

char	*convert_cor(char	*s)
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
	if (argc != 2)
		return (ft_printf("Usage: ./asm name_of_file.s\n"));
	if (!ft_strstr(argv[1], ".s"))
		return (ft_printf("Usage: ./asm name_of_file.s\n"));
	if ((fd = open(argv[1], O_RDONLY)) < 3)
		return (ft_printf("invalid file\n"));
	ops = 0;
	labels = 0;
	if (set_header(&header, fd))
		return (1);
	if (!(ops = set_argument_list(fd, &labels)))
		return (1);
	if (set_label_vars(labels, ops))
		return (1);
	cor_name = convert_cor(argv[1]);
	if ((fd = open(cor_name, O_WRONLY | O_TRUNC)) < 3)
		return (1);
	write_file(fd, ops, labels, &header);
	free(cor_name);
	free_ops_and_labels(ops, labels);
	return (0);

}


	/*ft_printf("name: %s\n", header.prog_name);
	ft_printf("comment: %s\n\n", header.comment);
	while (ops)
	{
		ft_printf("op: %s%\n", ops->op_name);
		ft_printf("op_code: %d\n", ops->op_code);
		ft_printf("size: %d\n", ops->size);
		ft_printf("index: %d\n", ops->index);
		ft_printf("size0: %d\n", ops->arg_sizes[0]);
		ft_printf("size1: %d\n", ops->arg_sizes[1]);
		ft_printf("size2: %d\n", ops->arg_sizes[2]);
		if (op_table[(int)ops->op_code - 1].descriptor)
			ft_printf("descriptor byte: %d\n", ops->descriptor);
		ft_printf("\n");
		ops = ops->next;
	//check if label names are only valid chars and not repeated
	*/
