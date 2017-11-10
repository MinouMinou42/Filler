/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolivier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:55:34 by nolivier          #+#    #+#             */
/*   Updated: 2017/03/23 16:12:05 by nolivier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define BUFF_SIZE 1000

# include <unistd.h>

struct	s_playable
{
	int					x;
	int					y;
	int					score;
	struct s_playable	*next;
};

struct	s_plateau
{
	char				**plateau;
	int					x;
	int					y;
	int					player_number;
};

struct	s_piece
{
	char				**piece;
	int					x;
	int					y;
	int					x_decal;
	int					y_decal;
};

struct	s_coord
{
	int					x;
	int					y;
};

struct	s_rest
{
	int					fd;
	char				*rest;
	struct s_rest		*next;
};

typedef struct s_plateau	t_plateau;
typedef struct s_piece		t_piece;
typedef struct s_playable	t_playable;
typedef struct s_coord		t_coord;
typedef struct s_rest		t_rest;
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		get_next_line(const int fd, char **line);
void	ft_freegrid(char **tab);
int		ft_play(t_plateau *salver, t_piece *chessman);
void	ft_print_pos(int x, int y);
void	ft_lstdel_posi(t_playable *position);
void	ft_playable_posi(t_plateau *salver,
		t_piece *chessman, t_playable **position);
int		ft_is_o(char c);
int		ft_is_x(char c);
void	ft_read_piece(t_piece *chessman);
void	ft_read_plateau(t_plateau *salver);
void	ft_read_size(char *line, int *x, int *y);
void	ft_calc_score_bis(t_plateau *salver,
		t_piece *chessman, t_playable *position);
void	ft_freeintgrid(int **tab);
void	ft_set_score(t_plateau *salver, int **tab_score);
void	ft_set_player(t_plateau *salver,
		int **tab_score, t_piece *chessman, t_playable *position);

#endif
