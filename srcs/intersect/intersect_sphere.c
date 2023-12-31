/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:21:31 by deelliot          #+#    #+#             */
/*   Updated: 2023/02/03 11:21:33 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

void	sphere_intersection(t_ray ray, void *sphere, t_world *world)
{
	t_quadratic	params;
	t_tuple		sphere_to_ray;
	t_intersect	temp;

	temp = set_intersect_info(((t_sphere *)sphere)->material, \
	((t_sphere *)sphere)->appearance, ((t_sphere *)sphere)->transform, \
		spherical_map);
	temp.shape = sphere;
	ray = ray_transform(&ray, &((t_sphere *)sphere)->transform.inverse);
	sphere_to_ray = tuple_sub(ray.origin, ((t_sphere *)sphere)->origin);
	params.a = dot_product(ray.direction, ray.direction);
	params.b = 2 * dot_product(ray.direction, sphere_to_ray);
	params.c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	params.discriminant = (params.b * params.b) - 4 * params.a * params.c;
	if (params.discriminant >= 0.0)
	{
		temp.time = (-params.b - sqrt(params.discriminant)) / (2 * params.a);
		if (vec_push(&world->intersections, &temp) == VEC_ERROR)
			handle_errors("vec_push malloc error sphere_intersection");
		temp.time = (-params.b + sqrt(params.discriminant)) / (2 * params.a);
		if (vec_push(&world->intersections, &temp) == VEC_ERROR)
			handle_errors("vec_push malloc error sphere_intersection");
	}
}
