/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:25 by armoulin          #+#    #+#             */
/*   Updated: 2020/01/21 16:08:27 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

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
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		exit_msg(ERROR_FILE, file, NULL, asmr);
	while ((ret = ft_gnl(fd, &line)))
	{
		if (ret == -1)
			exit_msg(ERROR_FILE, file, NULL, asmr);
		asmr->nb_line++;
		handle_line(line, asmr);
		free(line);
	}
	close(fd);
	if (asmr->label)
		exit_msg(ERROR_LABEL_ALONE, asmr->label, &(asmr->nb_line), asmr);
}
