/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:17:32 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/24 13:17:33 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_dataset *ai;

	if (argc > 2)
		sys_error(INPUT);
	else if (argc < 2)
		sys_message(USAGE);
	if (!(ai = (t_dataset *)ft_memalloc(sizeof(t_dataset))))
		sys_error(MALLOC);
	if (argc == 2)
	{
		sys_validator(ai, argv[1]);
		init_main(ai);
		render_display(ai);
	}
}
