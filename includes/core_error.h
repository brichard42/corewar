/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_error.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:55:15 by brichard          #+#    #+#             */
/*   Updated: 2020/01/09 14:58:06 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ERROR_H
# define CORE_ERROR_H
/*
**	DEFINE PARSING ERROR_CODE
*/

# define ERR_NO_CHAMP				0
# define ERR_FILE_NOT_COR			1
# define ERR_WRONG_ARG				2
# define ERR_INVALID_CHAMP_NUM		3
# define ERR_INVALID_DUMP_NUM		4
# define ERR_TO_MANY_CHAMPS			5
# define ERR_WRONG_PLAYER_NUM		6

# define ERR_MAGIC					7

# define ERR_NAME_TOO_SHORT			8

# define ERR_PAD_BEFORE_SIZE		9
# define ERR_MISSING_SIZE			10
# define ERR_SIZE_FORMAT			11
# define ERR_SIZE_NEG				12

# define ERR_COMMENT_TOO_SHORT		13
# define ERR_PAD_AFTER_COM			14

# define ERR_MISSING_CODE			15
# define ERR_CODE_TOO_LONG			16
# define ERR_BINARY_CORRUPTED		17
# define ERR_INVALID_VERB_NUM		18
# define ERR_FILE_NOT_OPEN			19

# define ERR_MSG0					"Error: No champion given.\n"
# define ERR_MSG1					"Error: Invalid file extension. (.cor)\n"
# define ERR_MSG2					"Error: Invalid argument.\n"
# define ERR_MSG3					"Error: Invalid following number after -n argument. [1 - 4]\n"
# define ERR_MSG4					"Error: Invalid following number after -dump argument. [1 - 2147483647]\n"
# define ERR_MSG5					"Error: Too many champions.\n"
# define ERR_MSG6					"Error: Player num not available. [1 - 4] <= Amount of players\n"

# define ERR_MSG7					"Error: Magic number (%s champion) is wrong or missing.\n"

# define ERR_MSG8					"Error: Wrong %s champion's name format.\n"

# define ERR_MSG9					"Error: Missing padding before %s champons's size.\n"
# define ERR_MSG10					"Error: Missing %s champion's size.\n"
# define ERR_MSG11					"Error: Wrong %s champion's size format.\n"
# define ERR_MSG12					"Error: Size of %s champion can't be negative.\n"

# define ERR_MSG13					"Error: Wrong comment format. (%s champion)\n"
# define ERR_MSG14					"Error: Missing padding after comment. (%s champion)\n"

# define ERR_MSG15					"Error: Binary is incomplete -> missing %s champion's code.\n"
# define ERR_MSG16					"Error: Code in %s champion's binary is too long.\n"
# define ERR_MSG17					"Error: Binary corrupted. (%s champion)\n"
# define ERR_MSG18					"Error: Invalid following number after -v argument. [1 - 64]\n"
# define ERR_MSG19					"Error: Error while opening file / file might not exist.\n"

# define ERR_MSG_NUM				20
# define MAX_ERR_MSG_SIZE			75

#endif
