/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:47:24 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/12 09:47:21 by taehokim         ###   ########.fr       */
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

int
	is_somebody_died(void)
{
	sp(vars()->somebody_died, "is_somebody_died post error");
	if (sem_wait(vars()->somebody_died))
	{
		printf("somebody died!\n");
		return (1);
	}
	return (0);
}
