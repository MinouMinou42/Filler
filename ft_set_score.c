/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_score.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:28:10 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/23 16:05:19 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_place_around(t_plateau *salver,
		int **tab_score, t_coord *p, int current)
{
	int			i;
	int			j;

	i = p->x - 1;
	while (i <= p->x + 1)
	{
		j = p->y - 1;
		while (j <= p->y + 1)
		{
			if ((i >= 0 && i < salver->x) && (j >= 0 && j < salver->y))
			{
				if (tab_score[i][j] == 1)
					tab_score[i][j] = current + 1;
				else if (tab_score[i][j] == -current - 1)
					tab_score[i][j] = 0;
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int		ft_place_around_adv(t_plateau *salver,
		int **tab_score, t_coord *p, int current)
{
	int			i;
	int			j;

	i = p->x - 1;
	while (i <= p->x + 1)
	{
		j = p->y - 1;
		while (j <= p->y + 1)
		{
			if ((i >= 0 && i < salver->x) && (j >= 0 && j < salver->y))
			{
				if (tab_score[i][j] == 1)
					tab_score[i][j] = -current - 1;
				else if (tab_score[i][j] == current + 1)
					tab_score[i][j] = 0;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void			ft_set_score(t_plateau *salver, int **tab_score)
{
	t_coord		p;
	int			current;
	int			find;

	current = 2;
	find = 1;
	while (find == 1)
	{
		find = 0;
		p.x = 0;
		while (p.x < salver->x)
		{
			p.y = 0;
			while (p.y < salver->y)
			{
				if (tab_score[p.x][p.y] == current)
					find = ft_place_around(salver, tab_score, &p, current);
				else if (tab_score[p.x][p.y] == -current)
					find = ft_place_around_adv(salver, tab_score, &p, current);
				p.y++;
			}
			p.x++;
		}
		current++;
	}
}
