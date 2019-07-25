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

void			render_color(int color, int x, int y, t_dataset *ai)
{
	ai->i = (x * (ai->bits / 8)) + (y * ai->var);
	ai->img_ptr[ai->i] = color;
	ai->img_ptr[++ai->i] = color >> 8;
	ai->img_ptr[++ai->i] = color >> 16;
}

unsigned int	render_gradient(double x, double y, int i, t_dataset *ai)
{
	ai->j = i + 1 - (log(2) / ai->calc) / log(2);
	ai->calc = sqrt(x * x + y * y);
	ai->rgb[2] = (unsigned char)(sin(0.01 * ai->j + 1) * 230 + 25);
	ai->rgb[1] = (unsigned char)(sin(0.023 * ai->j + 2) * 230 + 25);
	ai->rgb[0] = (unsigned char)(sin(0.026 * ai->j + 4) * 230 + 25);
	ai->grad = (ai->rgb[0] << 16) + (ai->rgb[1] << 8) + (ai->rgb[2] + 255);
	return (ai->grad);
}

void			render_interface(t_dataset *ai)
{
	if(!(ai->menu = mlx_xpm_file_to_image(ai->mlx, "./textures/menu.xpm", &(ai->menu_w), &(ai->menu_h))))
		sys_error(TEXTURE);
	if(!(ai->img_menu = (int*)mlx_get_data_addr(ai->menu, &(ai->menu_bits), &(ai->menu_sl), &(ai->menu_end))))
		sys_error(IMG_PTR);
	mlx_put_image_to_window(ai->mlx, ai->win, ai->menu, 0, 0);
	mlx_string_put(ai->mlx, ai->win, 50, 19, WHITE, ft_itoa(ai->itr));
	mlx_string_put(ai->mlx, ai->win, 70, 47, WHITE, ft_itoa(ai->zoom));
}

void			render_scene(t_dataset *ai)
{
	mlx_destroy_image(ai->mlx, ai->img);
	if(!(ai->img = mlx_new_image(ai->mlx, WDT, HGT)))
		sys_error(IMG);
	if(!(ai->img_ptr = mlx_get_data_addr(ai->img, &(ai->bits),
		&(ai->var), &(ai->endian))))
		sys_error(IMG_PTR);
	sys_option(ai);
	mlx_put_image_to_window(ai->mlx, ai->win, ai->img, 100, 0);
	render_interface(ai);
}

void			render_display(t_dataset *ai)
{
	if(!(ai->mlx = mlx_init()))
		sys_error(MLX);
	if(!(ai->win = mlx_new_window(ai->mlx, WDT, HGT, "Fractol")))
		sys_error(WIN);
	if(!(ai->img = mlx_new_image(ai->mlx, WDT, HGT)))
		sys_error(IMG);
	render_scene(ai);
	mlx_key_hook(ai->win, controls_keys, ai);
	mlx_mouse_hook(ai->win, controls_mouse, ai);
	mlx_hook(ai->win, CROSS, 0, sys_close, ai);
	mlx_hook(ai->win, MOTION, 0, formula_motion, ai);
	mlx_loop(ai->mlx);
}
