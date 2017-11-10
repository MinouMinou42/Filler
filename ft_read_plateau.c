/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_plateau.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:17:51 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/23 13:18:52 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"

void		ft_read_plateau(t_plateau *salver)
{
	char		*line;
	int			i;

	get_next_line(0, &line);
	ft_read_size(line + 8, &salver->x, &salver->y);
	free(line);
	salver->plateau = (char**)malloc(sizeof(char*) * (salver->x + 1));
	get_next_line(0, &line);
	free(line);
	i = 0;
	while (i < salver->x)
	{
		get_next_line(0, &line);
		salver->plateau[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
	salver->plateau[i] = NULL;
}
