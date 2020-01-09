/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_define.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:34:20 by brichard          #+#    #+#             */
/*   Updated: 2020/01/09 11:13:23 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_DEFINE_H
# define CORE_DEFINE_H

/*
**	USAGE MSG
*/
# define USG_MSG			"Usage: ./corewar --visual [-dump n_cycles] \
[(-n num) champ1.cor] ..."

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
# define F_VERBOSE_LIVE		1
# define F_VERBOSE_CYCLE	2
# define F_VERBOSE_OP		4
# define F_VERBOSE_DEAD		8
# define F_VERBOSE_PCMOVE	16
# define F_VERBOSE_AFF		32

/*
**	FILE EXTENSION
*/
# define DOT_COR			".cor"

/*
**	FUNC_TABS_SIZES
*/
# define RD_F_NUM			5
# define GET_F_NUM			5

/*
**	TYPES SIZES
*/
# define SIZEOF_INT32		sizeof(uint32_t)//MACRO ATTENTION

#endif
