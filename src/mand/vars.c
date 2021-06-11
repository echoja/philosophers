/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:47:24 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/11 08:44:00 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int
	is_finished(long id)
{
	return (vars()->notepme != 0 && vars()->remained_times[id] < 1);
}

t_vars
	*vars(void)
{
	static t_vars	t;

	return (&t);
}
