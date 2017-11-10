/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_score_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 12:47:33 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/23 16:03:32 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"

static void		ft_init_inttab(t_plateau *salver, int **tab_score)
{
	int			i;

	i = 0;
	while (i < salver->x)
	{
		tab_score[i] = (int*)malloc(sizeof(int) * salver->y);
		i++;
	}
	tab_score[i] = NULL;
}

static void		ft_set_empty(t_plateau *salver, int **tab_score)
{
	int			i;
	int			j;

	i = 0;
	while (i < salver->x)
	{
		j = 0;
		while (j < salver->y)
		{
			tab_score[i][j] = 1;
			j++;
		}
		i++;
	}
}

static int		ft_total_score(t_plateau *salver, int **tab_score)
{
	int			i;
	int			j;
	int			score;

	score = 0;
	i = 0;
	while (i < salver->x)
	{
		j = 0;
		while (j < salver->y)
		{
			if (tab_score[i][j] > 0)
				score += tab_score[i][j];
			j++;
		}
		i++;
	}
	return (score);
}

void			ft_calc_score_bis(t_plateau *salver,
		t_piece *chessman, t_playable *position)
{
	int			**tab_score;

	tab_score = (int**)malloc(sizeof(int*) * (salver->x + 1));
	ft_init_inttab(salver, tab_score);
	while (position)
	{
		ft_set_empty(salver, tab_score);
		ft_set_player(salver, tab_score, chessman, position);
		ft_set_score(salver, tab_score);
		position->score = ft_total_score(salver, tab_score);
		position = position->next;
	}
	ft_freeintgrid(tab_score);
}
