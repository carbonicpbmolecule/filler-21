/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:01:24 by jirwin            #+#    #+#             */
/*   Updated: 2020/07/28 10:37:12 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			parse_token(t_token *token)
{
	int	y;

	if (!(token->map = (char **)ft_memalloc(sizeof(char *) * token->height)))
		return (1);
	y = 0;
	while (y < token->height)
	{
		if (get_next_line(0, &(token->map[y])) != 1)
			return (1);
		y++;
	}
	return (0);
}
