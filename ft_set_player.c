/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:35:10 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/23 14:37:10 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_set_piece_player(int **tab_score,
		t_piece *chessman, t_playable *position)
{
	int			i;
	int			j;

	i = 0;
	while (i < chessman->x)
	{
		j = 0;
		while (j < chessman->y)
		{
			if (chessman->piece[i][j] == '*')
				tab_score[position->x + i][position->y + j] = 2;
			j++;
		}
		i++;
	}
}

void			ft_set_player(t_plateau *salver,
		int **tab_score, t_piece *chessman, t_playable *position)
{
	int			i;
	int			j;

	i = 0;
	while (i < salver->x)
	{
		j = 0;
		while (j < salver->y)
		{
			if (ft_is_o(salver->plateau[i][j]))
				tab_score[i][j] = (salver->player_number == 1) ? 2 : -2;
			else if (ft_is_x(salver->plateau[i][j]))
				tab_score[i][j] = (salver->player_number == 2) ? 2 : -2;
			j++;
		}
		i++;
	}
	ft_set_piece_player(tab_score, chessman, position);
}
