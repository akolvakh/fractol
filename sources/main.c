//norm done

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
		ft_putstr(argv[1]);
		sys_validator(argv[1], data);
		init_main(data);
		render_display(data);
	}
}
