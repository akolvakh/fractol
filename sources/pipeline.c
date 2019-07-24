/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:17:44 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/24 13:17:45 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			render_image(int color, int x, int y, t_dataset *data)//render color
{
	int	i;

	i = (x * (data->bpp / 8)) + (y * data->s1);
	data->img_ptr[i] = color;
	data->img_ptr[++i] = color >> 8;
	data->img_ptr[++i] = color >> 16;
}

unsigned int	render_color(double x, double y, int i, t_dataset *data)//
{
	unsigned int	color;
	double			magic;
	double			i2;

	magic = sqrt(x * x + y * y);
	i2 = i + 1 - (log(2) / magic) / log(2);
	data->a[0] = (unsigned char)(sin(0.026 * i2 + 4) * 230 + 25);
	data->a[1] = (unsigned char)(sin(0.023 * i2 + 2) * 230 + 25);
	data->a[2] = (unsigned char)(sin(0.01 * i2 + 1) * 230 + 25);
	color = (data->a[0] << 16) + (data->a[1] << 8) + (data->a[2] + 255);
	return (color);
}

void			render_interface(t_dataset *data)
{
	data->menu = mlx_xpm_file_to_image(data->mlx, "./textures/menu.xpm",
			&(data->menu_w), &(data->menu_h));
	data->img_menu = (int*)mlx_get_data_addr(data->menu, &(data->menu_bpp),
			&(data->menu_sl), &(data->menu_end));
	mlx_put_image_to_window(data->mlx, data->win, data->menu, 0, 0);
	mlx_string_put(data->mlx, data->win, 50, 19,
			0xFFFFFF, ft_itoa(data->itr));
	mlx_string_put(data->mlx, data->win, 70, 47, 0xFFFFFF, ft_itoa(data->zoom));
}

void			render_scene(t_dataset *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WDT, HGT);
	data->img_ptr = mlx_get_data_addr(data->img, &(data->bpp),
		&(data->s1), &(data->endian));
	sys_option(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 100, 0);
	render_interface(data);
}

void			render_display(t_dataset *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WDT, HGT, "Fractol");
	data->img = mlx_new_image(data->mlx, WDT, HGT);
	render_scene(data);
	mlx_key_hook(data->win, controls_keys, data);
	mlx_mouse_hook(data->win, controls_mouse, data);
	mlx_hook(data->win, CROSS, 0, sys_close, data);
	mlx_hook(data->win, MOTION, 0, motion, data);
	mlx_loop(data->mlx);
}
