/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:16:59 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/24 13:17:01 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

enum				e_keys
{
	TAB = 48,
	SPACE = 49,
	SHIFT = 257,
	MOTION = 6,
	A = 0,
	S = 1,
	D = 2,
	Q = 12,
	W = 13,
	E = 14,
	R = 15,
	CROSS = 17,
	ONE = 18,
	TWO = 19,
	THREE = 20,
	FOUR = 21,
	FIVE = 23,
	SIX = 22,
	SEVEN = 26,
	EIGTH = 28,
	PLUS = 24,
	MINUS = 27,
	P = 35,
	ESC = 53,
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	MIDDLE_CLICK = 3,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5,
	PAGE_UP = 116,
	PAGE_DOWN = 121,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
	RIGHT_ARROW = 124,
	LEFT_ARROW = 123
};

enum				e_fractols
{
	JULIA = 1,
	MANDEL = 2,
	SHIP = 3,
	TRICORN = 4,
	MANDELCUBED = 5
};

enum				e_colors
{
	YELLOW = 0xF5B201,
	CYAN = 0x3FB1B7,
	PINK = 0xFF0FFF,
	WHITE = 0xFFFFFF,
	RED = 0xCC0000,
	GREEN = 0x98FB98,
	BLUE = 0x0000FF,
	DARK_GREEN = 0x247812,
	BLACK = 0x000000
};

enum				e_display
{
	WDT = 1400,
	HGT = 800
};

enum				e_errors
{
	MAP = 1,
	MLX = 2,
	WIN = 3,
	VALUE = 4,
	FILE = 5,
	MALLOC = 6,
	USAGE = 7,
	INPUT = 8,
	START = 9,
	FINISH = 10,
	TEXTURE = 11,
	IMG = 12,
	IMG_PTR = 13
};

enum				e_moves
{
	LEFT = 11,
	RIGHT = 12,
	UP = 13,
	DOWN = 14
};

typedef struct		s_dataset
{
	void			*menu;
	int				*img_menu;
	void			*img;
	char			*img_ptr;
	void			*mlx;
	void			*win;
	unsigned char	rgb[3];
	int				bits;
	int				s1;
	int				menu_h;
	int				menu_w;
	int				menu_sl;
	int				menu_end;
	int				menu_bits;
	int				endian;
	double			color;
	int				itr;
	double			zoom;
	double			x;
	double			y;
	double			mvx;
	double			mvy;
	double			scale_x;
	double			scale_y;
	double			new_x;
	double			new_y;
	double			re;
	double			im;
	double			o_re;
	double			o_im;
	double			n_re;
	double			n_im;
	int				fractol;
	int				mvmouse;
}					t_dataset;

void				init_formula(t_dataset *ai);
void				init_julia(t_dataset *ai);
void				init_mandel(t_dataset *ai);
void				init_ship(t_dataset *ai);
void				init_main(t_dataset *ai);
int					controls_mouse(int mousekey, int x, int y, t_dataset *ai);
int					controls_buttons(int key, t_dataset *ai);
int					controls_arrows(int key, t_dataset *ai);
int					controls_numbers(int key, t_dataset *ai);
int					controls_keys(int key, t_dataset *ai);
void				formula_fractol(int c, t_dataset *ai);
void				formula_tricorn(t_dataset *ai);
void				formula_scale(int flag, int x, int y, t_dataset *ai);
int					formula_motion(int x, int y, t_dataset *ai);
void				algo_julia(t_dataset *ai);
void				algo_tricorn(t_dataset *ai);
void				algo_general(int flag, t_dataset *ai);
void				sys_validator(t_dataset *ai, char *input);
void				sys_error(int err);
void				sys_message(int msg);
void				sys_option(t_dataset *ai);
int					sys_close(t_dataset *ai);
void				render_display(t_dataset *ai);
void				render_interface(t_dataset *ai);
void				render_scene(t_dataset *ai);
void				render_image(int color, int x, int y, t_dataset *ai);
unsigned int		render_color(double x, double y, int i, t_dataset *ai);

#endif
