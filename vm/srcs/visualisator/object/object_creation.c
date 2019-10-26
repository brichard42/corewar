/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:36:26 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/26 17:33:34 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

SDL_Rect create_rect(int x, int y, int w, int h)
{
    SDL_Rect    result;

    result.x = x;
    result.y = y;
    result.w = w;
    result.h = h;
    return (result);
}

SDL_Point create_point(int x, int y)
{
	SDL_Point	result;

	result.x = x;
    result.y = y;
    return (result);
}

SDL_Color create_color(int r, int g, int b, int a)
{
	SDL_Color	result;

	result.r = r;
    result.g = g;
    result.b = b;
    result.a = a;
    return (result);
}
