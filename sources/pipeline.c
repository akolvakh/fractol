#include "fractol.h"

void	render_interface(t_a *exp)
{
	exp->menu = mlx_xpm_file_to_image(exp->mlx, "./textures/background.xpm",
			&(exp->menu_w), &(exp->menu_h));
	exp->img_menu = (int*)mlx_get_data_addr(exp->menu, &(exp->menu_bpp),
			&(exp->menu_sl), &(exp->menu_end));
	mlx_put_image_to_window(exp->mlx, exp->win, exp->menu, -1, -1);
}

int		render_menu(t_a *exp)
{
	char	*txt1;
	char	*txt2;
	char	*zoom;
	char	*maxinter;

	zoom = ft_itoa(exp->zoom);
	maxinter = ft_itoa(exp->maxinter);
	txt1 = ft_strjoin("Inter: ", maxinter);
	txt2 = ft_strjoin("Zoom: ", zoom);
	mlx_string_put(exp->mlx, exp->win, 10, 5, 0xFFFFFF, txt1);
	mlx_string_put(exp->mlx, exp->win, 10, 20, 0xFFFFFF, txt2);
	mlx_string_put(exp->mlx, exp->win, 10, 100, 0xFFFFFF, "1: Arrow Keys");
	mlx_string_put(exp->mlx, exp->win, 10, 150, 0xFFFFFF, "2: Up & Down");
	mlx_string_put(exp->mlx, exp->win, 10, 200, 0xFFFFFF, "3: Scrool Wheel");
	mlx_string_put(exp->mlx, exp->win, 10, 250, 0xFFFFFF, "4: L.Click & + -");
	mlx_string_put(exp->mlx, exp->win, 10, 300, 0xFFFFFF, "5: Space Bar");
	mlx_string_put(exp->mlx, exp->win, 10, 350, 0xFFFFFF, "6: R.Click");
	mlx_string_put(exp->mlx, exp->win, 10, 400, 0xFFFFFF, "7: Num Key 1-3");
	mlx_string_put(exp->mlx, exp->win, 10, 450, 0xFFFFFF, "8: Num Key 4 & 5");
	ft_strdel(&txt1);
	ft_strdel(&txt2);
	ft_strdel(&zoom);
	ft_strdel(&maxinter);
	return (0);
}

void	rendering(t_a *exp)
{
	//mlx_put_image_to_window(exp->mlx, exp->win, exp->img, 0, 0);
	mlx_destroy_image(exp->mlx, exp->img);
	exp->img = mlx_new_image(exp->mlx, WIDTH, HEIGHT);
	exp->imgpointer = mlx_get_data_addr(exp->img, &(exp->bpp), &(exp->s1), &(exp->endian));
	sys_option(exp);
	mlx_put_image_to_window(exp->mlx, exp->win, exp->img, 0, 0);
	render_interface(exp);
	render_menu(exp);
}

void	display(t_a *exp)
{
	exp->mlx = mlx_init();
	exp->win = mlx_new_window(exp->mlx, WIDTH, HEIGHT, "Fractol");
	exp->img = mlx_new_image(exp->mlx, WIDTH, HEIGHT);
	rendering(exp);
	mlx_key_hook(exp->win, keyhooks, exp);
	mlx_mouse_hook(exp->win, mousehook, exp);
	mlx_hook(exp->win, 6, 0, motion, exp);
	mlx_hook(exp->win, 17, 0, sys_close, exp);
	mlx_loop(exp->mlx);
}