/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:17:21 by akolvakh          #+#    #+#             */
/*   Updated: 2019/07/24 13:17:22 by akolvakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		formula_julia(t_dataset *data)
{
	data->oldr_k = data->new_k;
	data->old_l = data->new_l;
	data->new_k = data->oldr_k * data->oldr_k - data->old_l * data->old_l + data->k;
	data->new_l = 2 * data->oldr_k * data->old_l + data->l;
}

void		formula_mandel(t_dataset *data)
{
	data->oldr_k = data->new_k;
	data->old_l = data->new_l;
	data->new_k = data->oldr_k * data->oldr_k - data->old_l * data->old_l + data->p_k;
	data->new_l = 2 * data->oldr_k * data->old_l + data->p_l;
}

void		formula_mandelcubed(t_dataset *data)
{
	data->oldr_k = data->new_k;
	data->old_l = data->new_l;
	data->new_k = (data->oldr_k * data->oldr_k * data->oldr_k) - (data->old_l * data->oldr_k * data->old_l) - (2 * data->oldr_k * data->old_l * data->old_l) + data->p_k;
	data->new_l = (2 * data->oldr_k * data->oldr_k * data->old_l) - (data->old_l * data->old_l * data->old_l) + data->p_l;
}

void		formula_ship(t_dataset *data)
{
	data->oldr_k = data->new_k;
	data->old_l = data->new_l;
	data->new_k = data->oldr_k * data->oldr_k - data->old_l * data->old_l + data->p_k;
	data->new_l = fabs(2 * data->oldr_k * data->old_l) + data->p_l;
}

void		formula_tricorn(t_dataset *data)
{
	data->oldr_k = data->new_k;
	data->old_l = data->new_l * -1;
	data->new_k = data->oldr_k * data->oldr_k - data->old_l * data->old_l + data->p_k;
	data->new_l = 2 * data->oldr_k * data->old_l + data->p_l;
}
