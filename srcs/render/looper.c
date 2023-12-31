/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:55:16 by thakala           #+#    #+#             */
/*   Updated: 2023/02/12 17:16:12 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

void	loop_filters(t_win *win)
{
	win->world.filter = (win->world.filter + 1) % FILTER_COUNT;
	refresh_image(win);
}
