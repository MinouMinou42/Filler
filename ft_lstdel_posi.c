/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_posi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:36:30 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/23 15:58:25 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"

void		ft_lstdel_posi(t_playable *position)
{
	t_playable	*tmp;
	t_playable	*next;

	tmp = position;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}
