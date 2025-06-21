/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkostany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:21:08 by nkostany          #+#    #+#             */
/*   Updated: 2023/07/13 13:21:11 by nkostany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_path
{
	int		i;
	int		j;
	char	**cpy;
	int		nb_line;
}				t_path;

typedef struct s_vars
{
	char	**map;
	void	*img;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*floor;
	void	*wall;
	void	*red_key;
	void	*door_closed;
	void	*door_open;
	void	*forward_one;
	void	*forward_two;
	void	*backward_one;
	void	*backward_two;
	void	*left_one;
	void	*left_two;
	void	*right_one;
	void	*right_two;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
	int		door_x;
	int		door_y;
	int		nb_obj;
	int		nb_moves;
}				t_vars;

/* -- PRINTF -- */

int		arg_checker(va_list arguments, int c);
int		ft_printf(const char *s, ...);
int		print_for_percent(void);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *c);
int		ft_type_hex(unsigned int i, int c);
int		ptr_len(unsigned long long n);
int		print_ptr(unsigned long long n);
int		put_ptr(unsigned long long n);
int		ft_putnbr_uns(unsigned int n);
char	*ft_itoa(int n);

/* -- GNL -- */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		*get_next_line(int fd);
char		*readf(char *line, int fd);
char		*trim(char *stline);
char		*get_line(char *stline);

/* -- SO_LONG -- */

# define WALL "./img/wall.xpm"
# define FLOOR "./img/floor.xpm"
# define PLAYER "./img/idle_forward.xpm"
# define DOOR "./img/door_closed.xpm"
# define KEY "./img/Props.xpm"

int		main(int argc, char **argv);
char	**parsing(int argc, char **argv, t_path *path);
int		count_line(int fd);
void	check_pathing(t_path *path);
int		key_hook(int keycode, t_vars *vars);
int		ft_escape(t_vars *var);
void	ft_backward(t_vars *var);
void	ft_left(t_vars *var);
void	ft_forward(t_vars *var);
void	ft_right(t_vars *var);
void	print_wall(t_vars *var);
void	print_floor(t_vars *var);
void	print_door(t_vars *var);
void	print_player(t_vars *var);
void	print_key(t_vars *var);
void	initialize_map(t_vars *var);
char	**ft_tabdup(char **s1, t_path p);
int		is_door_open(t_vars *var);
void	free_map(char **tab);

#endif
