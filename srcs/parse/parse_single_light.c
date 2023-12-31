/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:38:12 by deelliot          #+#    #+#             */
/*   Updated: 2023/02/12 14:03:15 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RT.h"

static void	find_light_subobject_keyword(t_light *light, t_parser *parser)
{
	parser->c += ft_clear_whitespace(&parser->string[parser->c]);
	if (ft_strncmp(&parser->string[parser->c], "\"position\"", 10) == 0)
	{
		parser->c += sizeof("\"position\"") - 1;
		find_colon(parser);
		parse_tuple(&light->position, parser);
	}
	else if (ft_strncmp(&parser->string[parser->c], "\"intensity\"", 11) == 0)
	{
		parser->c += sizeof("\"intensity\"") - 1;
		find_colon(parser);
		parse_tuple(&light->intensity, parser);
	}
	else if (ft_strncmp(&parser->string[parser->c], "\"direction\"", 11) == 0)
	{
		parser->c += sizeof("\"direction\"") - 1;
		find_colon(parser);
		parse_tuple(&light->direction, parser);
	}
	else
		handle_parser_errors("syntax error light object", parser);
}

void	parse_single_light(t_parser *parser, t_light *light)
{
	find_light_subobject_keyword(light, parser);
	parser->c += ft_clear_whitespace(&parser->string[parser->c]);
	if (parser->string[parser->c] == ',')
	{
		parser->c++;
		parse_single_light(parser, light);
	}
	else if (!find_matching_bracket(parser))
		handle_parser_errors("light syntax error", parser);
}
