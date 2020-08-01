/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 18:01:21 by jirwin            #+#    #+#             */
/*   Updated: 2020/07/28 10:59:01 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			parse_player(t_filler *filler)
{
	char	*line;

	line = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "jirwin.filler]"))
		{
			if (line[10] == '1')
			{
				filler->player_symbol = 'O';
				filler->enemy_symbol = 'X';
			}
			else if (line[10] == '2')
			{
				filler->player_symbol = 'X';
				filler->enemy_symbol = 'O';
			}
			free(line);
			return (0);
		}
		free(line);
	}
	free(line);
	free(filler);
	return (1);
}
