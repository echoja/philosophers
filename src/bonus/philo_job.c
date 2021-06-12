/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:30:36 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/12 08:43:08 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int
	lock_near(void)
{
	if (sw(vars()->forks, "left sem_wait failed") ||
		sw(vars()->forks, "right sem_wait failed"))
		return (1);
	return (0);
}

int
	unlock_near(void)
{
	if (sp(vars()->forks, "left sem_post failed") ||
		sp(vars()->forks, "right sem_post failed"))
		return (1);
	return (0);
}

int
	philo_eat(long id)
{
	uint64_t	now;

	if (get_current_time(&vars()->recent_meal[id]))
		return (1);
	msg_take_fork(vars()->recent_meal[id], id);
	msg_eat(vars()->recent_meal[id], id);
	if (get_current_time(&now))
		return (1);
	msleep(vars()->tte);
	return (0);
}

int
	philo_sleep(long id)
{
	uint64_t	now;
	uint64_t	from_before;

	if (get_current_time(&now))
		return (1);
	from_before = now - vars()->recent_meal[id];
	msg_sleep(now, id);
	msleep(vars()->tts);
	return (0);
}

int
	philo_think(long id)
{
	uint64_t	now;

	if (get_current_time(&now))
		return (1);
	msg_think(now, id);
	return (0);
}
