/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:06:09 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/25 09:38:08 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"

static void		ft_filler(t_plateau *salver, t_piece *chessman)
{
	int			end;

	end = 0;
	while (!end)
	{
		ft_read_plateau(salver);
		ft_read_piece(chessman);
		if (ft_play(salver, chessman) < 0)
		{
			end = 1;
			ft_print_pos(0, 0);
		}
		ft_freegrid(salver->plateau);
		ft_freegrid(chessman->piece);
	}
}

int				main(void)
{
	char		*line;
	t_plateau	*salver;
	t_piece		*chessman;

	salver = (t_plateau*)malloc(sizeof(t_plateau));
	chessman = (t_piece*)malloc(sizeof(t_piece));
	line = NULL;
	get_next_line(0, &line);
	if (line)
	{
		salver->player_number = (int)(line[10] - '0');
		free(line);
	}
	ft_filler(salver, chessman);
	free(salver);
	free(chessman);
	return (1);
}
