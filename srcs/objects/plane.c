/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:05:04 by deelliot          #+#    #+#             */
/*   Updated: 2022/11/15 11:30:31 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*

t_transform	plane_transform_floor(void)
{
	t_transform	plane_transform;

	plane_transform.translation = point(0, 0, 0);
	plane_transform.rotation = point(0, 0, 0);
	plane_transform.scale = point(1, 1, 1);
	transform_object(&plane_transform);
	return (plane_transform);
}

t_transform	plane_transform_right_wall(void)
{
	t_transform	plane_transform;

	plane_transform.translation = point(0, 0, 5);
	plane_transform.rotation = point(M_PI_2, 0, -M_PI_4);
	plane_transform.scale = point(1, 1, 1);
	transform_object(&plane_transform);
	return (plane_transform);
}

t_transform	plane_transform_left_wall(void)
{
	t_transform	plane_transform;

	plane_transform.translation = point(0, 0, 5);
	plane_transform.rotation = point(M_PI_2, 0, M_PI_4);
	plane_transform.scale = point(1, 1, 1);
	transform_object(&plane_transform);
	return (plane_transform);
}

t_material	plane_material(void)
{
	return ((t_material){
		.ambient = 0.1,
		.diffuse = 0.65,
		.specular = 0.27,
		.shininess = 210,
		.init_colour = colour(1.0, 0.4, 0, 0.5),
		.col_mash = vector(0, 0, 0),
		.amb_col = vector(0, 0, 0),
		.dif_col = vector(0, 0, 0),
		.spec_col = vector(0, 0, 0)
	});
}

t_material	plane_material_floor(void)
{
	return ((t_material){
		.ambient = 0.1,
		.diffuse = 0.65,
		.specular = 0.27,
		.shininess = 210,
		.init_colour = colour(1.0, 0.0, 0.0, 0.5),
		.col_mash = vector(0, 0, 0),
		.amb_col = vector(0, 0, 0),
		.dif_col = vector(0, 0, 0),
		.spec_col = vector(0, 0, 0)
	});
}

t_material	plane_material_right_wall(void)
{
	return ((t_material){
		.ambient = 0.1,
		.diffuse = 0.65,
		.specular = 0.27,
		.shininess = 210,
		.init_colour = colour(1.0, 0, 0.3, 0.5),
		.col_mash = vector(0, 0, 0),
		.amb_col = vector(0, 0, 0),
		.dif_col = vector(0, 0, 0),
		.spec_col = vector(0, 0, 0)
	});
}

t_material	plane_material_left_wall(void)
{
	return ((t_material){
		.ambient = 0.1,
		.diffuse = 0.65,
		.specular = 0.27,
		.shininess = 210,
		.init_colour = colour(1.0, 0.4, 0, 0),
		.col_mash = vector(0, 0, 0),
		.amb_col = vector(0, 0, 0),
		.dif_col = vector(0, 0, 0),
		.spec_col = vector(0, 0, 0)
	});
}

t_object	plane(t_tuple origin, t_transform transform, t_material material)
{
	return ((t_object){
		.object.plane = (t_plane)
		{
			.origin = origin,
			.transform = transform,
			.material = material
		},
		.type = OBJECT_PLANE
	});
}
*/