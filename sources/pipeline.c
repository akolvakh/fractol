#include "fractol.h"

void	render_interface(t_dataset *data)
{
	data->menu = mlx_xpm_file_to_image(data->mlx, "./textures/background.xpm",
			&(data->menu_w), &(data->menu_h));
	data->img_menu = (int*)mlx_get_data_addr(data->menu, &(data->menu_bpp),
			&(data->menu_sl), &(data->menu_end));
	mlx_put_image_to_window(data->mlx, data->win, data->menu, -1, -1);
}

int		render_menu(t_dataset *data)
{
	char	*txt1;
	char	*txt2;
	char	*zoom;
	char	*maxinter;

	zoom = ft_itoa(data->zoom);
	maxinter = ft_itoa(data->maxinter);
	txt1 = ft_strjoin("Inter: ", maxinter);
	txt2 = ft_strjoin("Zoom: ", zoom);
	mlx_string_put(data->mlx, data->win, 10, 5, 0xFFFFFF, txt1);
	mlx_string_put(data->mlx, data->win, 10, 20, 0xFFFFFF, txt2);
	mlx_string_put(data->mlx, data->win, 10, 100, 0xFFFFFF, "1: Arrow Keys");
	mlx_string_put(data->mlx, data->win, 10, 150, 0xFFFFFF, "2: Up & Down");
	mlx_string_put(data->mlx, data->win, 10, 200, 0xFFFFFF, "3: Scrool Wheel");
	mlx_string_put(data->mlx, data->win, 10, 250, 0xFFFFFF, "4: L.Click & + -");
	mlx_string_put(data->mlx, data->win, 10, 300, 0xFFFFFF, "5: Space Bar");
	mlx_string_put(data->mlx, data->win, 10, 350, 0xFFFFFF, "6: R.Click");
	mlx_string_put(data->mlx, data->win, 10, 400, 0xFFFFFF, "7: Num Key 1-3");
	mlx_string_put(data->mlx, data->win, 10, 450, 0xFFFFFF, "8: Num Key 4 & 5");
	ft_strdel(&txt1);
	ft_strdel(&txt2);
	ft_strdel(&zoom);
	ft_strdel(&maxinter);
	return (0);
}

void	rendering(t_dataset *data)
{
	//mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->imgpointer = mlx_get_data_addr(data->img, &(data->bpp), &(data->s1), &(data->endian));
	sys_option(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	render_interface(data);
	render_menu(data);
}

void	display(t_dataset *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	rendering(data);
	mlx_key_hook(data->win, keyhooks, data);
	mlx_mouse_hook(data->win, mousehook, data);
	mlx_hook(data->win, 6, 0, motion, data);
	mlx_hook(data->win, 17, 0, sys_close, data);
	mlx_loop(data->mlx);
}