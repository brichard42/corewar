/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_define.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:13:47 by brichard          #+#    #+#             */
/*   Updated: 2019/11/07 13:38:18 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_DEFINE_H
# define CORE_DEFINE_H

/*
**	TEST VALUE
*/
# define TRUE			1
# define FALSE			0

/*
**	RETURN VALUE
*/
# define SUCCESS		0
# define FAILURE		-1

/*
**	ON / OFF
*/
# define ON				1
# define OFF			0

/*
**	PARSING OPTIONS
*/
# define O_DUMP			"-dump"
# define O_CHP_NUM		"-n"
# define O_VERBOSE		"-v"
# define O_VISU			"--visual"

/*
**	FILE EXTENSION
*/
# define DOT_COR		".cor"

/*
**	FUNC_TABS_SIZES
*/
# define RD_F_NUM		5
# define GET_F_NUM		4

/*
**	TYPES SIZES
*/
# define SIZEOF_INT32	sizeof(uint32_t)

#endif
