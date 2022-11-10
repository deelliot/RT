#include "RTv1.h"

int	find_shape(t_object *shape, t_parser *parser)
{
	find_double_quote(parser);
	if (ft_strncmp(&parser->string[parser->c], "plane\"", 9) == 0)
	{
		parse_plane(&shape->object.plane, parser);
		return (true);
	}
	else if (ft_strncmp(&parser->string[parser->c], "sphere\"", 10) == 0)
	{
		parse_sphere(&shape->object.sphere, parser);
		return (true);
	}
	else if (ft_strncmp(&parser->string[parser->c], "cone\"", 10) == 0)
	{
		parse_cone(&shape->object.cone, parser);
		return (true);
	}
	else if (ft_strncmp(&parser->string[parser->c], "cylinder\"", 10) == 0)
	{
		parse_cylinder(&shape->object.cylinder, parser);
		return (true);
	}
	return (false);
}

void	parse_shapes(t_world *world, t_parser *parser)
{
	t_object	object;

	find_colon(parser);
	find_open_bracket(parser);
	find_open_bracket(parser);
	while (find_shape(&object, parser))
	{
		if (vec_push(&world->objects, &object) == VEC_ERROR)
			handle_errors("vec_push light error");
		if (!find_matching_bracket(parser))
			handle_errors("brackets syntax error");
	}
}