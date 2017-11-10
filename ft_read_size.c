/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 14:03:12 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/23 14:06:41 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_read_size(char *line, int *x, int *y)
{
	*x = ft_atoi(line);
	while (ft_isdigit(*line))
		line += 1;
	line += 1;
	*y = ft_atoi(line);
}
