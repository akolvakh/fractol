/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:26:03 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:26:05 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_dataset *data;

	if (argc < 2)
		sys_message(USAGE);
	if (argc > 2)
		sys_error(INPUT);
	if (!(data = (t_dataset *)ft_memalloc(sizeof(t_dataset))))
		sys_error(MALLOC);
	data->color = 1;
	if (argc == 2)
	{
		sys_validator(data, argv[1]);
		init_main(data);
		render_display(data);
	}
}
