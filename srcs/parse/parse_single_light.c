/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_single_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thakala <thakala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:19:20 by deelliot          #+#    #+#             */
/*   Updated: 2022/11/16 14:14:58 by thakala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

static void	find_light_subobject_keyword(t_light *light, t_parser *parser)
{
	find_double_quote(parser);
	if (ft_strncmp(&parser->string[parser->c], "position\"", 9) == 0)
	{
		parser->c += sizeof("position\"") - 1;
		find_colon(parser);
		parse_tuple(&light->position, parser);
	}
	else if (ft_strncmp(&parser->string[parser->c], "intensity\"", 10) == 0)
	{
		parser->c += sizeof("intensity\"") - 1;
		find_colon(parser);
		parse_tuple(&light->intensity, parser);
	}
	else
		handle_errors("syntax error light object");
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
		handle_errors("light syntax error");
}
