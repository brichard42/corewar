/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_error.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:55:15 by brichard          #+#    #+#             */
/*   Updated: 2020/01/22 18:54:08 by tlandema         ###   ########.fr       */
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

# define ERR_NO_CHP_AFTER_NUM		20
# define ERR_TOO_MUCH_CHAMP			21

# define ERR_MSG0 "Error: No champion given.\n"
# define ERR_MSG1 "Error: Invalid file extension. (.cor)\n"
# define ERR_MSG2 "Error: Invalid argument.\n"
# define ERR_MSG3 "Error: Invalid following number after -n ,rgument. [1 - 4]\n"
# define ERR_MSG4 "Error: Invalid following number after -dump arg. [INT]\n"
# define ERR_MSG5 "Error: Too many champions.\n"
# define ERR_MSG6 "Error: Player num not available. [1 - 4]\n"

# define ERR_MSG7 "Error: In Binary: Magic num is wrong or missing.(%s champ)\n"

# define ERR_MSG8 "Error: In Binary: Wrong %s champion's name format.\n"

# define ERR_MSG9 "Error: In Binary: Missing padding before %s champ's size.\n"
# define ERR_MSG10 "Error: In Binary: Missing %s champion's size.\n"
# define ERR_MSG11 "Error: In Binary: Wrong %s champion's size format.\n"
# define ERR_MSG12 "Error: In Binary: Size of %s champion can't be negative.\n"

# define ERR_MSG13 "Error: In Binary: Wrong comment format. (%s champion)\n"
# define ERR_MSG14 "Error: In Binary: Missing padding after com. (%s champ)\n"

# define ERR_MSG15 "Error: Binary is incomplete -> missing %s champ's code.\n"
# define ERR_MSG16 "Error: Code in %s champion's binary is too long.\n"
# define ERR_MSG17 "Error: Binary corrupted. (%s champion)\n"
# define ERR_MSG18 "Error: Invalid following number after -v arg. [1 - 16]\n"
# define ERR_MSG19 "Error: Error while opening file / file might not exist.\n"
# define ERR_MSG20 "Error: Missing champ file after given champ number.\n"
# define ERR_MSG21 "Error: Too much champions given.\n"

# define ERR_MSG_NUM				22

#endif
