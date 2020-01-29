/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:25 by armoulin          #+#    #+#             */
/*   Updated: 2020/01/29 14:24:12 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Stores each characters of the name, stop at '"'.
*/
static void	get_name(char *line, t_asm *asmr)
{
	while (*line && *line != '"')
	{
		if (asmr->i_name > PROG_NAME_LENGTH)
			exit_msg(ERROR_NAME_LENGTH, NULL, NULL, asmr);
		asmr->header.prog_name[asmr->i_name++] = *line++;
	}
	if (*line++ == '"')
	{
		asmr->is_name = FALSE;
		asmr->got_name = TRUE;
		asmr->header.prog_name[asmr->i_name] = '\0';
	}
	while (ft_isspace(*line))
		line++;
	if (*line)
		exit_msg(ERROR_SYNTAX, NULL, &(asmr->nb_line), asmr);
}

/*
** Same as for name.
*/
static void	get_comment(char *line, t_asm *asmr)
{
	while (*line && *line != '"')
	{
		if (asmr->i_comment > COMMENT_LENGTH)
			exit_msg(ERROR_COMMENT_LEN, NULL, NULL, asmr);
		asmr->header.comment[asmr->i_comment++] = *line++;
	}
	if (*line++ == '"')
	{
		asmr->is_comment = FALSE;
		asmr->got_comment = TRUE;
		asmr->header.comment[asmr->i_comment] = '\0';
	}
	while (ft_isspace(*line))
		line++;
	if (*line)
		exit_msg(ERROR_SYNTAX, NULL, &(asmr->nb_line), asmr);
}

/*
** Beginning of reading name, skip cmd string and whitespaces, set "is_name".
*/
static void	handle_name(char *line, t_asm *asmr)
{
	line += ft_strlen(NAME_CMD_STRING);
	while (ft_isspace(*line))
		line++;
	if (*line != '"')
		exit_msg(ERROR_SYNTAX, NULL, &(asmr->nb_line), asmr);
	line++;
	asmr->is_name = TRUE;
	get_name(line, asmr);
}

/*
** Same as for name.
*/
static void	handle_comment(char *line, t_asm *asmr)
{
	line += ft_strlen(COMMENT_CMD_STRING);
	while (ft_isspace(*line))
		line++;
	if (*line != '"')
		exit_msg(ERROR_SYNTAX, NULL, &(asmr->nb_line), asmr);
	line++;
	asmr->is_comment = TRUE;
	get_comment(line, asmr);
}

/*
** Use 'is_***' to read name and comment on muliple lines.
** Get name then get comment.
*/
void		get_header(char *line, t_asm *asmr)
{
	if (asmr->is_name)
		get_name(line, asmr);
	else if (asmr->is_comment)
		get_comment(line, asmr);
	else if (!asmr->got_name
		&& !ft_strncmp(line, NAME_CMD_STRING,
						ft_strlen(NAME_CMD_STRING)))
		handle_name(line, asmr);
	else if (!asmr->got_comment
		&& !ft_strncmp(line, COMMENT_CMD_STRING,
						ft_strlen(COMMENT_CMD_STRING)))
		handle_comment(line, asmr);
	else
		exit_msg(ERROR_SYNTAX, NULL, &(asmr->nb_line), asmr);
}
