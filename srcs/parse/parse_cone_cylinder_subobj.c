/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone_cylinder_subobj.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:36:27 by deelliot          #+#    #+#             */
/*   Updated: 2023/02/12 14:03:26 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

void	find_min(t_parser *parser, t_object *object)
{
	t_fl	min;

	parser->c += sizeof("\"min\"") - 1;
	find_colon(parser);
	min = rt_atof(parser);
	if (object->type == OBJECT_CONE)
		object->object.cone.min = min;
	else
		object->object.cylinder.min = min;
}

void	find_max(t_parser *parser, t_object *object)
{
	t_fl	max;

	parser->c += sizeof("\"max\"") - 1;
	find_colon(parser);
	max = rt_atof(parser);
	if (object->type == OBJECT_CONE)
		object->object.cone.max = max;
	else
		object->object.cylinder.max = max;
}

void	find_closed(t_parser *parser, t_object *object)
{
	int		closed;

	parser->c += sizeof("\"closed\"") - 1;
	find_colon(parser);
	parser->c += ft_clear_whitespace(&parser->string[parser->c]);
	if (parser->string[parser->c] == '1')
		closed = true;
	else if (parser->string[parser->c] == '0')
		closed = false;
	else
		handle_parser_errors("cone/cylinder syntax error", parser);
	if (object->type == OBJECT_CONE)
		object->object.cone.closed = closed;
	else
		object->object.cylinder.closed = closed;
	parser->c++;
}

int	cone_and_cylinder_objects(t_parser *parser, t_object *object)
{
	parser->c += ft_clear_whitespace(&parser->string[parser->c]);
	if (!ft_strncmp(&parser->string[parser->c], "\"min\"", 5))
		find_min(parser, object);
	else if (!ft_strncmp(&parser->string[parser->c], "\"max\"", 5))
		find_max(parser, object);
	else if (!ft_strncmp(&parser->string[parser->c], "\"closed\"", 8))
		find_closed(parser, object);
	else
		return (false);
	return (true);
}
