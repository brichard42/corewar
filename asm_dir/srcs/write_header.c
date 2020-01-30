/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by armoulin          #+#    #+#             */
/*   Updated: 2020/01/30 14:41:29 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Couldn't directly read and write the maximum bytes for champion's name,
** as if name doesn't fill all memory, it could be corrupted.
** So write until first '\0' then fill ourself.
** Precisly, we fill to 129 (max = 128 + 1 for '\0'), then we add 3 more
** blanks bytes because the memory works with group of 4 bytes.
** (128 % 4 = 0 ; 129 % 4 = 1 ; 132 % 4 = 0)
*/

void	write_magic_name_size(t_asm *asmr, int32_t fd)
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

/*
** Same remark as previous function.
*/

void	write_comment(t_asm *asmr, int32_t fd)
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
