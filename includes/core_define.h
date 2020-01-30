/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_define.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:34:20 by brichard          #+#    #+#             */
/*   Updated: 2020/01/30 16:59:43 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_DEFINE_H
# define CORE_DEFINE_H

/*
**	USAGE MSG
*/
# define USG_MSG2			"	-v : Verbose"
# define USG_MSG3			"		 0: Doesn't show lives"
# define USG_MSG4			"		 2: Show cycle num"
# define USG_MSG5			"		 4: Show ops"
# define USG_MSG6			"		 8: Show pc deaths"
# define USG_MSG7			"		16: Show char from aff operation"

/*
**	TEST VALUE
*/
# define TRUE				1
# define FALSE				0

/*
**	RETURN VALUE
*/
# define SUCCESS			0
# define FAILURE			-1

/*
**	ON / OFF
*/
# define ON					1
# define OFF				0

/*
**	PARSING OPTIONS
*/
# define O_DUMP				"-dump"
# define O_CHP_NUM			"-n"
# define O_VERBOSE			"-v"
# define O_VISU				"--visual"
# define F_VERBOSE_LIVE		0x00
# define F_VERBOSE_CYCLE	0x02
# define F_VERBOSE_OP		0x04
# define F_VERBOSE_DEAD		0x08
# define F_VERBOSE_AFF		0x10

/*
**	FILE EXTENSION
*/
# define DOT_COR			".cor"

/*
**	FUNC_TABS_SIZES
*/
# define RD_F_NUM			5
# define GET_F_NUM			5

#endif
