/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_refraction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:19:55 by deelliot          #+#    #+#             */
/*   Updated: 2023/02/03 12:46:01 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

static void	check_container(t_vec *container, t_intersect *current)
{
	uint64_t	j;

	j = 0;
	while (j < container->len)
	{
		if (current->shape->shape_id == \
			((t_intersect *)vec_get(container, j))->shape->shape_id)
		{
			if (vec_remove(container, j) != VEC_SUCCESS)
				handle_errors("unable to remove object from container");
			return ;
		}
		j++;
	}
	if (vec_push(container, current) != VEC_SUCCESS)
		handle_errors("unable to add object to container");
}

static void	set_n2(t_intersect	*current, t_vec	container, t_hit *hit)
{
	if (current->time == hit->intersection.time)
	{
		if (container.len == 0)
			hit->computations.n2 = 1.0;
		else
			hit->computations.n2 = \
				((t_intersect *)vec_get(&container, \
				container.len - 1))->material.refractive_index;
	}
}

void	compute_refraction_index(t_world *world, t_hit *hit)
{
	t_vec		container;
	uint64_t	i;
	t_intersect	*current;

	i = 0;
	vec_new(&container, 1, sizeof(t_intersect));
	while (i < world->intersections.len)
	{
		current = (t_intersect *)vec_get(&world->intersections, i++);
		if (current->time == hit->intersection.time)
		{
			if (container.len == 0)
				hit->computations.n1 = 1.0;
			else
				hit->computations.n1 = \
					((t_intersect *)vec_get(&container, \
					container.len - 1))->material.refractive_index;
		}
		check_container(&container, current);
		set_n2(current, container, hit);
	}
	vec_free (&container);
}
