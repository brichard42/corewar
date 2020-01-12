/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 17:08:31 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static char	*get_name(char *title, t_asm *asmr)
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

void		write_file(t_asm *asmr, char *title)
{
	char *name;

	name = get_name(title, asmr);
	
	free(name);
}