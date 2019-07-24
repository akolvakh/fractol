/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:25:09 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:25:12 by akolvakh         ###   ########.fr       */
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
	LEFT_ARROW = 123,
	MOTION = 6
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
	DEF_COLOR = 0xF5B201,
	UNDEF_COLOR = 0x247812
};

enum				e_display
{
	WIDTH = 1400,
	HEIGHT = 800
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
	int				menu_h;
	int				menu_w;
	int				menu_sl;
	int				menu_end;
	int				menu_bpp;

	void			*mlx;
	void			*win;
	void			*img;
	char			*img_ptr;

	int				bpp;
	int				s1;
	int				endian;
	int				color;
	int				fractol;

	double			**map;
	double			x;
	double			y;
	double			zoom;
	double			movex;
	double			movey;


	double			clickx;
	double			clicky;
	double			tmpx;
	double			tmpy;


	double			defre;
	double			defim;
	double			oldre;
	double			oldim;
	double			newre;
	double			newim;

	int				iteration;
	int				i;
	double			pr;
	double			pi;


	int				movemouse;
	double			x2;
	double			y2;

	unsigned char	a[3];
}					t_dataset;

void				init_formula(t_dataset *data);
void				init_julia(t_dataset *data);
void				init_mandel(t_dataset *data);
void				init_ship(t_dataset *data);
void				init_main(t_dataset *data);
int					controls_mouse(int mousekey, int x, int y, t_dataset *data);
int					controls_buttons(int key, t_dataset *data);
int					controls_arrows(int key, t_dataset *data);
int					controls_numbers(int key, t_dataset *data);
int					controls_keys(int key, t_dataset *data);
void				formula_tricorn(t_dataset *data);
void				formula_ship(t_dataset *data);
void				formula_mandelcubed(t_dataset *data);
void				formula_mandel(t_dataset *data);
void				formula_juliacubed(t_dataset *data);
void				formula_julia(t_dataset *data);
void				algo_tricorn(t_dataset *data);
void				algo_julia(t_dataset *data);
void				algo_mandel(t_dataset *data);
void				algo_ship(t_dataset *data);
void				algo_juliacubed(t_dataset *data);
void				algo_mandelcubed(t_dataset *data);
void				scale_up(int x, int y, t_dataset *data);
void				scale_down(int x, int y, t_dataset *data);
int					motion(int x, int y, t_dataset *data);
void				sys_validator(t_dataset *data, char *input);
void				sys_error(int error);
void				sys_message(int message);
void				sys_option(t_dataset *data);
int					sys_close(t_dataset *data);
void				render_display(t_dataset *data);
void				render_interface(t_dataset *data);
void				render_scene(t_dataset *data);
void				render_image(int color, int x, int y, t_dataset *data);
unsigned int		render_color(double x, double y, int i, t_dataset *data);

#endif
