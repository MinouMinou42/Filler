/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playable_posi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:43:04 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/25 09:41:27 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"

static int			ft_check_point(t_plateau *salver,
		t_coord *point, t_coord *ptr, int *overlaped)
{
	if (salver->player_number == 1)
	{
		if (ft_is_o(salver->plateau[point->x + ptr->x][point->y + ptr->y]))
		{
			if (*overlaped > 0)
				return (-1);
			else
				*overlaped = 1;
		}
		else if (salver->plateau[point->x + ptr->x][point->y + ptr->y] != '.')
			return (-1);
	}
	else if (salver->player_number == 2)
	{
		if (ft_is_x(salver->plateau[point->x + ptr->x][point->y + ptr->y]))
		{
			if (*overlaped > 0)
				return (-1);
			else
				*overlaped = 1;
		}
		else if (salver->plateau[point->x + ptr->x][point->y + ptr->y] != '.')
			return (-1);
	}
	return (1);
}

static int			ft_verif_posi(t_plateau *salver,
		t_piece *chessman, t_coord *point)
{
	int			overlaped;
	t_coord		ptr;

	overlaped = 0;
	ptr.x = 0;
	while (ptr.x < chessman->x - chessman->x_decal)
	{
		ptr.y = 0;
		while (ptr.y < chessman->y - chessman->y_decal)
		{
			if (chessman->piece[ptr.x + chessman->x_decal]
					[ptr.y + chessman->y_decal] == '*')
			{
				if ((point->x + ptr.x >= salver->x) ||
						(point->y + ptr.y >= salver->y) ||
						ft_check_point(salver, point, &ptr, &overlaped) < 0)
					return (-1);
			}
			ptr.y++;
		}
		ptr.x++;
	}
	return ((overlaped) ? 1 : -1);
}

static void			ft_create_playable(t_playable **position, int x, int y)
{
	t_playable	*tmp;

	if (*position == NULL)
	{
		*position = (t_playable*)malloc(sizeof(t_playable));
		tmp = *position;
		tmp->x = x;
		tmp->y = y;
		tmp->next = NULL;
	}
	else
	{
		tmp = *position;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = (t_playable*)malloc(sizeof(t_playable));
		tmp = tmp->next;
		tmp->x = x;
		tmp->y = y;
		tmp->next = NULL;
	}
}

void				ft_playable_posi(t_plateau *salver,
		t_piece *chessman, t_playable **position)
{
	t_coord		point;

	point.x = 0;
	while (salver->plateau[point.x] != NULL)
	{
		point.y = 0;
		while (salver->plateau[point.x][point.y] != '\0')
		{
			if (ft_verif_posi(salver, chessman, &point) > 0)
			{
				ft_create_playable(position, point.x - chessman->x_decal,
						point.y - chessman->y_decal);
			}
			point.y++;
		}
		point.x++;
	}
}
