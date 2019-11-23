/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underliner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:42:06 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/22 15:51:52 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	underliner(t_window *win, t_vm *env)
{
	SDL_Point	point;
	int			text[3];

	point = create_point(15, 198);
	if (create_tab_int3(text, 17, TEXT2 + env->mem_owner[count], BOLD)
			== FAILURE)
}
