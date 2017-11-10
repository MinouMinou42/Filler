/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:13:05 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/25 09:42:03 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"

static void		ft_read_piece_decal(t_piece *chessman)
{
	int		i;
	int		j;

	chessman->x_decal = chessman->x;
	chessman->y_decal = chessman->y;
	i = 0;
	while (chessman->piece[i] != NULL)
	{
		j = 0;
		while (chessman->piece[i][j] != '\0')
		{
			if (chessman->piece[i][j] == '*')
			{
				if (j < chessman->y_decal)
					chessman->y_decal = j;
				if (i < chessman->x_decal)
					chessman->x_decal = i;
			}
			j++;
		}
		i++;
	}
}

void			ft_read_piece(t_piece *chessman)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	ft_read_size(line + 6, &chessman->x, &chessman->y);
	free(line);
	chessman->piece = (char**)malloc(sizeof(char*) * (chessman->x + 1));
	i = 0;
	while (i < chessman->x)
	{
		get_next_line(0, &line);
		chessman->piece[i] = line;
		i++;
	}
	chessman->piece[i] = NULL;
	ft_read_piece_decal(chessman);
}
