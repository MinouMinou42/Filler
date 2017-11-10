/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:25:14 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/25 09:39:01 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_seek_highscore(t_playable *position)
{
	int			score_max;
	int			i;
	int			max;

	score_max = position->score;
	max = 0;
	i = 0;
	while (position)
	{
		if (position->score > score_max)
		{
			score_max = position->score;
			max = i;
		}
		i++;
		position = position->next;
	}
	return (max);
}

static void		ft_best_play(t_playable *position)
{
	int			i;
	int			max;

	max = ft_seek_highscore(position);
	i = 0;
	while (i < max)
	{
		position = position->next;
		i++;
	}
	ft_print_pos(position->x, position->y);
}

int				ft_play(t_plateau *salver, t_piece *chessman)
{
	t_playable	*position;

	position = NULL;
	ft_playable_posi(salver, chessman, &position);
	if (position == NULL)
		return (-1);
	ft_calc_score_bis(salver, chessman, position);
	ft_best_play(position);
	ft_lstdel_posi(position);
	return (1);
}
