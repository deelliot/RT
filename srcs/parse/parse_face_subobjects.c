/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_face_subobjects.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:36:47 by deelliot          #+#    #+#             */
/*   Updated: 2023/02/12 13:55:18 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

static void	find_face_continued(t_texture *texture, t_parser *parser, int face)
{
	if (ft_strncmp(&parser->string[parser->c], "\"bl\"", 4) == 0)
	{
		parser->c += sizeof("\"bl\"") - 1;
		find_colon(parser);
		parse_tuple(&texture->bl[face], parser);
	}
	else if (ft_strncmp(&parser->string[parser->c], "\"br\"", 4) == 0)
	{
		parser->c += sizeof("\"br\"") - 1;
		find_colon(parser);
		parse_tuple(&texture->br[face], parser);
	}
	else if (ft_strncmp(&parser->string[parser->c], "\"name\"", 6) == 0)
	{
		parser->c += sizeof("\"name\"") - 1;
		find_colon(parser);
		parse_name(&texture->image[face], parser);
		open_ppm(&texture->image[face]);
	}
	else
		handle_parser_errors("incorrect corner in face", parser);
}

static void	find_face_keyword(t_texture *texture, t_parser *parser, int face)
{
	parser->c += ft_clear_whitespace(&parser->string[parser->c]);
	if (ft_strncmp(&parser->string[parser->c], "\"main\"", 6) == 0)
	{
		parser->c += sizeof("\"main\"") - 1;
		find_colon(parser);
		parse_tuple(&texture->main[face], parser);
	}
	else if (ft_strncmp(&parser->string[parser->c], "\"ul\"", 4) == 0)
	{
		parser->c += sizeof("\"ul\"") - 1;
		find_colon(parser);
		parse_tuple(&texture->ul[face], parser);
	}
	else if (ft_strncmp(&parser->string[parser->c], "\"ur\"", 4) == 0)
	{
		parser->c += sizeof("\"ur\"") - 1;
		find_colon(parser);
		parse_tuple(&texture->ur[face], parser);
	}
	else
		find_face_continued(texture, parser, face);
}

void	set_face(t_texture *texture, t_parser *parser, int face)
{
	find_face_keyword(texture, parser, face);
	parser->c += ft_clear_whitespace(&parser->string[parser->c]);
	if (parser->string[parser->c] == ',')
	{
		parser->c++;
		set_face(texture, parser, face);
	}
	else if (!find_matching_bracket(parser))
		handle_parser_errors("face syntax error", parser);
}

void	set_default_face(t_texture *texture, int face)
{
	texture->main[face] = point(1, 1, 1);
	texture->ul[face] = point(1, 1, 1);
	texture->ur[face] = point(1, 1, 1);
	texture->bl[face] = point(1, 1, 1);
	texture->br[face] = point(1, 1, 1);
}
