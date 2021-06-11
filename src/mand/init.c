/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:07:00 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/10 10:01:33 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "philosophers.h"

int
	init2(void)
{
	long		i;
	long		nop;
	uint64_t	t;

	nop = vars()->nop;
	if (get_current_time(&t))
		return (print_and_return_code(1, "init current time failed"));
	i = -1;
	while (++i < nop)
	{
		vars()->recent_meal[i] = t;
		vars()->available_forks[i] = 2;
		if (vars()->notepme > 0)
			vars()->remained_times[i] = vars()->notepme;
		else
			vars()->remained_times[i] = -1;
	}
	vars()->start = t;
	vars()->color[0] = ANSI_COLOR_RED;
	vars()->color[1] = ANSI_COLOR_GREEN;
	vars()->color[2] = ANSI_COLOR_YELLOW;
	vars()->color[3] = ANSI_COLOR_BLUE;
	vars()->color[4] = ANSI_COLOR_MAGENTA;
	vars()->color[5] = ANSI_COLOR_CYAN;
	return (0);
}

int
	init(void)
{
	long		i;
	long		nop;

	nop = vars()->nop;
	if (!m(&vars()->philos, sizeof(pthread_t) * nop) ||
		!m(&vars()->watchers, sizeof(pthread_t) * nop) ||
		!m(&vars()->locks, sizeof(pthread_mutex_t) * nop) ||
		!m(&vars()->remained_times, sizeof(long) * nop) ||
		!m(&vars()->available_forks, sizeof(long) * nop) ||
		!m(&vars()->recent_meal, sizeof(uint64_t) * nop))
		return (print_and_return_code(1, "memory allocation error"));
	if (mi(&vars()->once, "once init failed"))
		return (1);
	if (mi(&vars()->somebody_died_lock, "somebody_died_lock init failed"))
		return (1);
	if (mi(&vars()->even_first_lock, "even_first_lock init failed"))
		return (1);
	i = -1;
	while (++i < nop)
		if (mi(&vars()->locks[i], "mutex init failed"))
			return (1);
	return (init2());
}
