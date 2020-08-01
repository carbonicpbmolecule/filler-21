/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:59:30 by jirwin            #+#    #+#             */
/*   Updated: 2020/07/28 11:05:41 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	calc_sum(t_board *board, t_token *token, int y, int x)
{
	int	j;
	int	i;
	int	sum;
	int	player_counter;

	sum = 0;
	player_counter = 0;
	j = -1;
	while (++j < token->height)
	{
		i = -1;
		while (++i < token->width)
		{
			if (token->map[j][i] == '*')
			{
				if ((y + j) < 0 || (y + j) >= board->height
				|| (x + i) < 0 || (x + i) >= board->width
				|| board->heat_map[y + j][x + i] == -2)
					return (-1);
				player_counter += (board->heat_map[y + j][x + i] == -1) ? 1 : 0;
				sum += board->heat_map[y + j][x + i];
			}
		}
	}
	return ((player_counter == 1) ? sum : -1);
}

void		calc_coords(t_board *board, t_token *token, t_filler *filler)
{
	int	j;
	int	i;
	int	sum;
	int	min_sum;

	min_sum = INT_MAX;
	j = 0;
	while (j < board->height - token->height + 1)
	{
		i = 0;
		while (i < board->width - token->width + 1)
		{
			sum = calc_sum(board, token, j, i);
			if (sum != -1 && sum < min_sum)
			{
				filler->y = j;
				filler->x = i;
				min_sum = sum;
			}
			i++;
		}
		j++;
	}
}
