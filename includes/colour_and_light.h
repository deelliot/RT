/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_and_light.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:00:58 by deelliot          #+#    #+#             */
/*   Updated: 2023/02/12 16:53:54 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOUR_AND_LIGHT_H
# define COLOUR_AND_LIGHT_H

# include "RT.h"

enum e_colour
{
	COLOUR_RED = 0x00FF0000,
	COLOUR_GREEN = 0x0000FF00,
	COLOUR_BLUE = 0x000000FF,
	COLOUR_BLACK = 0x00000000,
	COLOUR_WHITE = 0x00FFFFFF,
	COLOUR_TURQOUISE = 0x40E0D0U,
	COLOUR_YELLOW = 0xFFF200,
	COLOUR_PURPLE = 0x8A00C2,
	COLOUR_HOT_PINK = 0xFB48C4
};

typedef struct s_phong
{
	t_tuple	eye;
	t_tuple	light;
	t_tuple	surface_normal;
	t_tuple	reflection;
	int		in_shadow;
	t_fl	shadow_occlusion;
}				t_phong;

typedef struct s_snell_calculations
{
	t_fl	n_ratio;
	t_fl	cos_i;
	t_fl	sin2_t;
	t_fl	cos_t;
}				t_snell;

#endif
