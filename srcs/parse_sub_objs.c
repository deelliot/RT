#include "RTv1.h"

int	find_subobject_keyword(t_parser *parser,
	t_tuple *origin,
	t_transform *transform,
	t_material *material)
{
	find_double_quote(parser);
	if (ft_strncmp(&parser->string[parser->c], "origin\"", 8) == 0)
	{
		parser->c += 8;
		parse_tuple(origin, parser);
		return (true);
	}
	else if (ft_strncmp(&parser->string[parser->c], "transform\"", 10) == 0)
	{
		parse_transform(&transform, parser);
		return (true);
	}
	else if (ft_strncmp(&parser->string[parser->c], "material\"", 9) == 0)
	{
		parser->c += 10;
		parse_tuple(&material, parser);
		return (true);
	}
	return (false);
}

int	plane_subobject_keywords(t_parser *parser, t_object *shape)
{
	return (find_subobject_keyword(parser, &shape->object.plane.origin,
		&shape->object.plane.transform,
		&shape->object.plane.material));
}

int	sphere_subobject_keywords(t_parser *parser, t_object *shape)
{
	return (find_subobject_keyword(parser, &shape->object.sphere.origin,
		&shape->object.sphere.transform,
		&shape->object.sphere.material));
}

int	cone_subobject_keywords(t_parser *parser, t_object *shape)
{
	return (find_subobject_keyword(parser, &shape->object.cone.origin,
		&shape->object.cone.transform,
		&shape->object.cone.material));
}

int	cylinder_subobject_keywords(t_parser *parser, t_object *shape)
{
	return (find_subobject_keyword(parser, &shape->object.cylinder.origin,
		&shape->object.cylinder.transform,
		&shape->object.cylinder.material));
}

int	dispatch_find_subobject_keyword(t_parser *parser, t_object *shape)
{
	static const t_subobject_keyword_fn	kw_fns[] =
	{
		plane_subobject_keywords,
		sphere_subobject_keywords,
		cone_subobject_keywords,
		cylinder_subobject_keywords
	};

	return (kw_fns[shape->type](parser, shape));
}

void	parse_tuple(t_tuple *tuple, t_parser *parser)
{
	int i;

	i = 0;
	find_colon(parser);
	parser->c += ft_clear_whitespace(parser->string);
	if (parser->string[parser->c] == '[')
	{
		while (i < 3)
		{
			tuple->array[i] = rt_atof(&parser->string, parser->c);
			if (i < 2 && ++parser->c != ',')
				handle_errors("array syntax error");
			i++;
		}
		if (parser->string[++parser->c] == ']')
		{
			parser->c++;
			return ;
		}
	}
	handle_errors("DENIED: parse_tuple");
}

int	find_transform_keyword(t_transform *transform, t_parser *parser)
{
	find_double_quote(parser);
	if (ft_strncmp(&parser->string[parser->c], "translation\"", 12) == 0)
	{
		parser->c += 12;
		parse_tuple(&transform->translation, parser);
		return (true);
	}
	else if (ft_strncmp(&parser->string[parser->c], "rotation\"", 9) == 0)
	{
		parser->c += 9;
		parse_tuple(&transform->rotation, parser);
		return (true);
	}
	else if (ft_strncmp(&parser->string[parser->c], "scale\"", 6) == 0)
	{
		parser->c += 6;
		parse_tuple(&transform->scale, parser);
		return (true);
	}
	return (false);
}

void	parse_transform(t_transform *transform, t_parser *parser)
{
	parser->c += 10;
	find_colon(parser);
	find_open_bracket(parser);
	if (find_matching_bracket(parser))
		return ;
	else
	{
		while (find_transform_keyword(&transform, parser))
			parse_transform(transform, parser);
		if (!find_matching_bracket(parser))
			handle_errors("syntax error");
	}
}

void	parse_material(t_material *material, t_parser *parser)
{

}

