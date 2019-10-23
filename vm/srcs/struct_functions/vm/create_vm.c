/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:20:49 by paullaurent       #+#    #+#             */
/*   Updated: 2019/10/23 12:42:03 by paullaurent      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm    *create_vm(void)
{
    t_vm    *new_vm;

    new_vm = (t_vm *)ft_memalloc(sizeof(t_vm));
    if (new_vm != NULL)
        *new_vm = init_vm();
    return (new_vm);
}