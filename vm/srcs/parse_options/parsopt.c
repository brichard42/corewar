/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsopt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 04:19:51 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/24 06:07:53 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	option_parser(int ac, char **av, t_vm *env)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strequ(av[i], "-v"))
			env->visu_on = TRUE;
		i++;
	}
}
