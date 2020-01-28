/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:25 by armoulin          #+#    #+#             */
/*   Updated: 2020/01/28 16:07:03 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static void	get_last_label(t_asm *asmr)
{
	t_cmd	*new;

	new = new_elem(asmr);
	new->label = asmr->label;
	if (ft_strchr(new->label, SEPARATOR_CHAR))
		new->multi_label = TRUE;
	asmr->label = NULL;
	asmr->label_size = 0;
	new->nb_line = asmr->nb_line;
	asmr->list = add_elem(asmr->list, new);
}

/*
** Skip all withspaces.
** Get the header (name + comment).
** Get instructions.
*/
static void	handle_line(char *line, t_asm *asmr)
{
	while (*line && ft_isspace(*line))
		line++;
	if (!(*line) || *line == COMMENT_CHAR)
		return ;
	else if (!asmr->got_name || !asmr->got_comment)
		get_header(line, asmr);
	else
		get_op(line, asmr);
}

/*
** Open the file and handle line one by one.
*/
void		read_file(char *file, t_asm *asmr)
{
	int		fd;
	int		ret;

	if ((fd = open(file, O_RDONLY)) < 0)
		exit_msg(ERROR_FILE, file, NULL, asmr);
	while ((ret = ft_gnl(fd, &asmr->line)))
	{
		if (ret == -1)
			exit_msg(ERROR_FILE, file, NULL, asmr);
		asmr->nb_line++;
		handle_line(asmr->line, asmr);
		ft_strdel(&asmr->line);
	}
	if (close(fd) < 0)
		exit_msg(ERROR_CLOSE_RFILE, NULL, NULL, asmr);
	if (asmr->label)
		get_last_label(asmr);
	ft_strdel(&asmr->line);
}
