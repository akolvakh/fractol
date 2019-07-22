#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

enum				e_keys
{
	Q = 12, E = 14, R = 15,
	ONE = 18, TWO = 19,
	THREE = 20, FOUR = 21,
	TAB = 1, SHIFT = 2,
	P = 35, ESC = 53,
	CLICK = 1, SCROLL_UP = 4,
	SCROLL_DOWN = 5,
	UPKEY = 126, W = 13,
	DOWNKEY = 125, S = 1,
	LEFTKEY = 123, A = 0,
	RIGHTKEY = 124, D = 2,
};

enum				e_colors
{
	YELLOW = 0xF5B201, CYAN = 0x3FB1B7,
	PINK = 0xFF0FFF, WHITE = 0xFFFFFF,
	RED = 0xCC0000, GREEN = 0x98FB98,
	BLUE = 0x0000FF, DEF_COLOR = 0xF5B201
};

enum				e_display
{
	START_X = 100, START_Y = 100,
	WIDTH = 1400, HEIGHT = 800
};

enum				e_errors
{
	MAP = 1, MLX = 2,
	WIN = 3, VALUE = 4,
	FILE = 5, MALLOC = 6,
	USAGE = 7, INPUT = 8,
	START = 9, FINISH = 10,
};

enum				e_moves
{
	LEFT = 11, RIGHT = 12,
	UP = 13, DOWN = 14
};

typedef struct		s_dataset
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*imgpointer;
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
	double			cre;
	double			cim;
	double			oldre;
	double			oldim;
	double			newre;
	double			newim;
	double			pr;
	double			pi;
	int				maxinter;
	int				i;
	double			clickx;
	double			clicky;
	double			tmpx;
	double			tmpy;
	int				movemouse;
	double			x2;
	double			y2;


	void			*menu;
	int				*img_menu;
	int				menu_h;
	int				menu_w;
	int				menu_sl;
	int				menu_end;
	int				menu_bpp;

		unsigned char	chan[3];
}					t_dataset;

void				putimage(t_dataset *data, int x, int y, int color);

unsigned int		colormagic(t_dataset *data,int i, double x, double y);

int					render_menu(t_dataset *data);

void				init_julia(t_dataset *data);
void				init_mandel(t_dataset *data);
void				init_ship(t_dataset *data);
void				init_carpet(t_dataset *data);
void				init_main(t_dataset *data);

int					mousehook(int mousekey, int x, int y, t_dataset *data);
int					keyhooks3(int key, t_dataset *data);
int					keyhooks2(int key, t_dataset *data);
int					keyhooks(int key, t_dataset *data);

int					isfilled(int x, int	y, t_dataset *data);
void				carpetfx(t_dataset *data);
void				tricornfx(t_dataset *data);
void				juliafx(t_dataset *data);
void				mandelfx(t_dataset *data);
void				shipfx(t_dataset *data);
void				juliacubedfx(t_dataset *data);
void				mandelcubedfx(t_dataset *data);


void				zoomin(int x, int y, t_dataset *data);
void				zoomout(int x, int y, t_dataset *data);
int					motion(int x, int y, t_dataset *data);


void				mandelassign(t_dataset *data);


void				sys_validator(char *str, t_dataset *data);
int					sys_close(t_dataset *data);
void				sys_error(int error);
void				sys_message(int message);
void				sys_option(t_dataset *data);


void				display(t_dataset *data);
void				render_interface(t_dataset *data);
void				rendering(t_dataset *data);


#endif
