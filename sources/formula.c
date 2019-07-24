/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mandel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 21:28:11 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/23 21:28:12 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"////

void		formula_julia(t_dataset *data)
{
	data->oldre = data->newre;
	data->oldim = data->newim;
	data->newre = data->oldre * data->oldre - data->oldim * data->oldim + data->defre;
	data->newim = 2 * data->oldre * data->oldim + data->defim;
}

void		formula_juliacubed(t_dataset *data)
{
	data->oldre = data->newre;
	data->oldim = data->newim;
	data->newre = (data->oldre * data->oldre * data->oldre) - (data->oldim * data->oldim * data->oldre) - (2 * data->oldre * data->oldim * data->oldim) + data->defre;
	data->newim = (3 * data->oldre * data->oldre * data->oldim) - (data->oldim * data->oldim * data->oldim) + data->defim;
}

void		formula_mandel(t_dataset *data)
{
	data->oldre = data->newre;
	data->oldim = data->newim;
	data->newre = data->oldre * data->oldre -
			data->oldim * data->oldim + data->pr;
	data->newim = 2 * data->oldre * data->oldim + data->pi;
}

void		formula_mandelcubed(t_dataset *data)
{
	data->oldre = data->newre;
	data->oldim = data->newim;
	data->newre = (data->oldre * data->oldre * data->oldre) -
		(data->oldim * data->oldre * data->oldim) -
			(2 * data->oldre * data->oldim * data->oldim) + data->pr;
	data->newim = (2 * data->oldre * data->oldre * data->oldim) -
			(data->oldim * data->oldim * data->oldim) + data->pi;
}

void		formula_ship(t_dataset *data)
{
	data->oldre = data->newre;
	data->oldim = data->newim;
	data->newre = data->oldre * data->oldre -
		data->oldim * data->oldim + data->pr;
	data->newim = fabs(2 * data->oldre * data->oldim) + data->pi;
}

void		formula_tricorn(t_dataset *data)
{
	data->oldre = data->newre;
	data->oldim = data->newim * -1;
	data->newre = data->oldre * data->oldre -
			data->oldim * data->oldim + data->pr;
	data->newim = 2 * data->oldre * data->oldim + data->pi;
}
