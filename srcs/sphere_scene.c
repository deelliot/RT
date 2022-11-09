#include "RTv1.h"

t_canvas	scene_canvas(void)
{
	return ((t_canvas){.vertical = HEIGHT, .horizontal = WIDTH});
}

t_tuple	camera_sphere_origin(void)
{
	return (point(0, 1.5, -5));
}

t_transform	floor_transform(void)
{
	t_transform	d;

	d.translation = point(0, 0, 0);
	d.rotation = point(0, 0, 0);
	d.scale = point(10, 0.01, 10);
	transform_object(&d);
	return (d);
}

t_transform	left_wall_transform(void)
{
	t_transform	d;

	d.translation = point(0, 0, 5);
	d.rotation = point(M_PI_2, 0, (- M_PI_4));
	d.scale = point(10, 0.01, 10);
	transform_object(&d);
	return (d);
}

t_transform	right_wall_transform(void)
{
	t_transform	d;

	d.translation = point(0, 0, 5);
	d.rotation = point(M_PI_2, 0, M_PI_4);
	d.scale = point(10, 0.01, 10);
	transform_object(&d);
	return (d);
}

t_transform	sphere_1_transform(void)
{
	t_transform	d;

	d.translation = point(-0.5, 1, 0.5);
	d.rotation = point(0, 0, 0);
	d.scale = point(1, 1, 1);
	transform_object(&d);
	return (d);
}

t_material	sphere_1_mat(void)
{
	return ((t_material){
		.ambient = 0.0,
		.diffuse = 0.7,
		.specular = 0.3,
		.shininess = 200,
		.init_colour = colour(1.0, 0.1, 1.0, 0.5),
		.pattern = default_checkered_pattern(),
		.col_mash = vector(0, 0, 0),
		.amb_col = vector(0, 0, 0),
		.dif_col = vector(0, 0, 0),
		.spec_col = vector(0, 0, 0)
	});
}

t_material	floor_mat(void)
{
	return ((t_material){
		.ambient = 0.1,
		.diffuse = 0.7,
		.specular = 0.0,
		.shininess = 200,
		.pattern = default_ring_pattern(),
		.init_colour = colour(1.0, 1.0, 0.9, 0.9),
		.col_mash = vector(0, 0, 0),
		.amb_col = vector(0, 0, 0),
		.dif_col = vector(0, 0, 0),
		.spec_col = vector(0, 0, 0)
	});
}

t_material	left_wall_mat(void)
{
	return ((t_material){
		.ambient = 0.1,
		.diffuse = 0.7,
		.specular = 0.0,
		.shininess = 200,
		.init_colour = colour(1.0, 1.0, 0.0, 0.0),
		.pattern = default_gradient_pattern(),
		.col_mash = vector(0, 0, 0),
		.amb_col = vector(0, 0, 0),
		.dif_col = vector(0, 0, 0),
		.spec_col = vector(0, 0, 0)
	});
}

t_material	right_wall_mat(void)
{
	return ((t_material){
		.ambient = 0.1,
		.diffuse = 0.7,
		.specular = 0.0,
		.shininess = 200,
		.init_colour = colour(1.0, 0.0, 1.0, 0.0),
		.col_mash = vector(0, 0, 0),
		.amb_col = vector(0, 0, 0),
		.dif_col = vector(0, 0, 0),
		.spec_col = vector(0, 0, 0)
	});
}

t_transform	sphere_2_transform(void)
{
	t_transform	d;

	d.translation = point(1.5, 0.5, -0.5);
	d.rotation = point(0, 0, 0);
	d.scale = point(0.5, 0.5, 0.5);
	transform_object(&d);
	return (d);
}

t_material	sphere_2_mat(void)
{
	return ((t_material){
		.ambient = 0.0,
		.diffuse = 0.7,
		.specular = 0.3,
		.shininess = 200,
		.init_colour = colour(1.0, 0.5, 1.0, 0.1),
		.col_mash = vector(0, 0, 0),
		.amb_col = vector(0, 0, 0),
		.dif_col = vector(0, 0, 0),
		.spec_col = vector(0, 0, 0)
	});
}

t_transform	sphere_3_transform(void)
{
	t_transform	d;

	d.translation = point(-1.5, 0.33, -0.75);
	d.rotation = point(0, 0, 0);
	d.scale = point(0.33, 0.33, 0.33);
	transform_object(&d);
	return (d);
}

t_material	sphere_3_mat(void)
{
	return ((t_material){
		.ambient = 0.0,
		.diffuse = 0.7,
		.specular = 0.3,
		.shininess = 200,
		.init_colour = colour(1.0, 1, 0.8, 0.1),
		.col_mash = vector(0, 0, 0),
		.amb_col = vector(0, 0, 0),
		.dif_col = vector(0, 0, 0),
		.spec_col = vector(0, 0, 0)
	});
}

t_light	default_light(void)
{
	return ((t_light){
		.position = point(-10, 10, -10),
		.intensity = colour(1, 1, 1, 1),
		.transform = default_transform_1(),
	});
}

t_transform	camera_sphere_transform(void)
{
	t_transform	d;

	d.translation = point(-1, 0, 0);
	d.rotation = point(0, 0, 0);
	d.scale = point(1, 1, 1);
	transform_object(&d);
	return (d);
}

void	sphere_world(t_world *world)
{
	t_object	floor;
	t_object	left_wall;
	t_object	right_wall;
	t_object	sphere_1;
	t_object	sphere_2;
	t_object	sphere_3;
	t_light		light;
	t_mtx		view_matrix;

	light = default_light();
	world->camera = camera(camera_sphere_origin(), camera_sphere_transform(), M_PI_2, default_canvas());
	view_matrix = view_transform(world->camera.origin, world->camera.center_of_interest, vector(0, 1, 0));
	matrix_multi_square(&world->camera.transform.matrix, &view_matrix, 4);
	world->camera.transform.inverse = world->camera.transform.matrix;
	matrix_inversion(&world->camera.transform.inverse, 4);
	floor = sphere(default_origin(), floor_transform(), floor_mat());
	left_wall = sphere(default_origin(), left_wall_transform(), left_wall_mat());
	right_wall = sphere(default_origin(), right_wall_transform(), right_wall_mat());
	sphere_1 = sphere(default_origin(), sphere_1_transform(), sphere_1_mat());
	sphere_2 = sphere(default_origin(), sphere_2_transform(), sphere_2_mat());
	sphere_3 = sphere(default_origin(), sphere_3_transform(), sphere_3_mat());

	if (vec_push(&world->objects, &floor) == VEC_ERROR)
		handle_errors("unable to malloc for world object");
	if (vec_push(&world->objects, &left_wall) == VEC_ERROR)
		handle_errors("unable to malloc for world object");
	if (vec_push(&world->objects, &right_wall) == VEC_ERROR)
		handle_errors("unable to malloc for world object");
	if (vec_push(&world->objects, &sphere_1) == VEC_ERROR)
		handle_errors("unable to malloc for world object");
	if (vec_push(&world->objects, &sphere_2) == VEC_ERROR)
		handle_errors("unable to malloc for world object");
	if (vec_push(&world->objects, &sphere_3) == VEC_ERROR)
		handle_errors("unable to malloc for world object");
	if (vec_push(&world->lights, &light) == VEC_ERROR)
		handle_errors("unable to malloc for light");
}
