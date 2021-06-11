/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:01:58 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/11 08:48:28 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include "philosophers.h"
#include <string.h>

int
	philo_one_loop(long id, pthread_t *watcher)
{
	if (vars()->somebody_died)
		return (R_SOMEBODY_DIED);
	if (lock_near(id))
		return (R_ERROR);
	vars()->remained_times[id]--;
	if (tc(watcher, watch_thread, (void *)id, "watcher create failed"))
		return (R_ERROR);
	if (td(*watcher, "watcher detach failed"))
		return (R_ERROR);
	if (philo_eat(id))
		return (R_ERROR);
	if (unlock_near(id))
		return (R_ERROR);
	if (philo_sleep(id))
		return (R_ERROR);
	if (philo_think(id))
		return (R_ERROR);
	if (is_finished(id))
		return (R_BREAK);
	return (R_CONTINUE);
}

void
	*thread_philo_one(void *arg)
{
	long		id;
	pthread_t	watcher;
	int			res;

	id = (long)arg;
	while (1)
	{
		res = philo_one_loop(id, &watcher);
		if (res == R_SOMEBODY_DIED || res == R_BREAK)
			return ((void *)0);
		if (res == R_ERROR)
			return ((void *)1);
	}
	return ((void *)0);
}

int
	tc_step_2(long init_i)
{
	long	i;

	if (ml(&vars()->even_first_lock, "efl lock failed"))
		return (1);
	i = init_i;
	while (i < vars()->nop)
	{
		if (tc(&vars()->philos[i], thread_philo_one,
				(long *)i, "philo create failed"))
			return (1);
		i += 2;
	}
	if (mul(&vars()->even_first_lock, "efl unlock failed"))
		return (1);
	return (0);
}

void
	*start_philo_half(void *even)
{
	long	i;
	long	init_i;
	long	res;

	if ((long)even)
		init_i = 0;
	else
		init_i = 1;
	if (tc_step_2(init_i))
		return ((void *)1);
	i = init_i;
	while (i < vars()->nop)
	{
		if (tj(vars()->philos[i], (void **)&res, "philo join failed"))
			return ((void *)1);
		i += 2;
	}
	return (0);
}

int
	start_philo_one(void)
{
	long		i;
	pthread_t	starter[2];

	if (init())
		return (print_and_return_code(1, "error while init"));
	i = -1;
	if (tc(&starter[0], start_philo_half, (void *)1, "even start failed") ||
		tc(&starter[1], start_philo_half, (void *)0, " odd start failed"))
		return (1);
	if (tj(starter[0], (void **)&i, "even join failed") ||
		tj(starter[1], (void **)&i, " odd join failed"))
		return (1);
	safe_exit(0);
	return (0);
}
