/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_define.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:34:20 by brichard          #+#    #+#             */
/*   Updated: 2020/01/16 15:37:47 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_DEFINE_H
# define CORE_DEFINE_H

/*
**	USAGE MSG
*/
# define USG_MSG1			"Usage: ./corewar --visual [-dump n_cycles] \
[(-n num) champ1.cor] ..."
# define USG_MSG2			"	-v : Verbose"
# define USG_MSG3			"	  - 1: Show lives"
# define USG_MSG4			"	  - 4: Show op"

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
# define F_VERBOSE_LIVE		0x01
# define F_VERBOSE_CYCLE	0x02
# define F_VERBOSE_OP		0x04
# define F_VERBOSE_DEAD		0x08
# define F_VERBOSE_PCMOVE	0x10
# define F_VERBOSE_AFF		0x20

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
