/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 17:08:31 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static char		*get_name(char *title, t_asm *asmr)
{
	char 	*name;
	size_t	length;

	length = ft_strlen(title);
	if (title[length - 1] != 's' || title[length - 2] != '.')
		exit_msg(ERROR_FILE_NAME, NULL, NULL, asmr);
	if (!(name = ft_strnew(length + 2)))
		exit_msg(ERROR_MALLOC, NULL, NULL, asmr);
	ft_strcpy(name, title);
	name[length - 1] = 'c';
	name[length] = 'o';
	name[length + 1] = 'r';
	return (name);
}

static int32_t	open_file(t_asm *asmr, char *file)
{
	int32_t	fd;

	if ((fd = open(file, O_CREAT | O_RDWR | O_TRUNC)) < 0)
		exit_msg(ERROR_FILE_OPEN, file, NULL, asmr);
	return (fd);
}

static void		write_magic_name_size(t_asm *asmr, int32_t fd)
{
	size_t	name_size;
	size_t	i;
	char	c;

	write_nb_4(asmr, fd, (int32_t)asmr->header.magic);
	c = '\0';
	name_size = ft_strlen(asmr->header.prog_name);
	if (write(fd, asmr->header.prog_name, name_size) != (int)name_size)
		exit_msg(ERROR_FILE_WRITE, NULL, NULL, asmr);
	i = PROG_NAME_LENGTH - name_size + 4;
	while (i--)
		if (write(fd, &c, 1) != 1)
			exit_msg(ERROR_FILE_WRITE, NULL, NULL, asmr);
	write_nb_4(asmr, fd, (int32_t)asmr->header.prog_size);
}

static void		write_comment(t_asm *asmr, int32_t fd)
{
	size_t	comment_size;
	size_t	i;
	char	c;

	c = '\0';
	comment_size = ft_strlen(asmr->header.comment);
	if (write(fd, asmr->header.comment, comment_size) != (int)comment_size)
			exit_msg(ERROR_FILE_WRITE, NULL, NULL, asmr);
	i = COMMENT_LENGTH - comment_size + 4;
	while (i--)
		if (write(fd, &c, 1) != 1)
			exit_msg(ERROR_FILE_WRITE, NULL, NULL, asmr);	
}

void			write_file(t_asm *asmr, char *title)
{
	char 	*name;
	int32_t	fd;

	name = get_name(title, asmr);
	fd = open_file(asmr, name);
	free(name);
	write_magic_name_size(asmr, fd);
	write_comment(asmr, fd);
}