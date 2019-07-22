
#include "fractol.h"

int				main(int argc, char **argv)
{
	t_a *exp;

	if (argc < 2)
		sys_message(USAGE);
	if (argc > 2)//
		sys_error(INPUT);
	if (!(exp = (t_a *)ft_memalloc(sizeof(t_a))))
		sys_error(MALLOC);
	exp->color = 1;
	if (argc == 2)
	{
		sys_validator(argv[1], exp);
		init_main(exp);
		display(exp);
	}
}
