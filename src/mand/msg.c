/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:44:36 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/11 08:46:27 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	msg_take_fork(uint64_t t, long id)
{
	pthread_mutex_lock(&vars()->somebody_died_lock);
	if (!vars()->somebody_died)
	{
		put_msg(t, id, ANSI_COLOR_BLUE, "has taken a fork");
		put_msg(t, id, ANSI_COLOR_BLUE, "has taken a fork");
	}
	pthread_mutex_unlock(&vars()->somebody_died_lock);
}

void	msg_eat(uint64_t t, long id)
{
	pthread_mutex_lock(&vars()->somebody_died_lock);
	if (!vars()->somebody_died)
		put_msg(t, id, ANSI_COLOR_CYAN, "is eating");
	pthread_mutex_unlock(&vars()->somebody_died_lock);
}

void	msg_sleep(uint64_t t, long id)
{
	pthread_mutex_lock(&vars()->somebody_died_lock);
	if (!vars()->somebody_died)
		put_msg(t, id, ANSI_COLOR_MAGENTA, "is sleeping");
	pthread_mutex_unlock(&vars()->somebody_died_lock);
}

void	msg_think(uint64_t t, long id)
{
	pthread_mutex_lock(&vars()->somebody_died_lock);
	if (!vars()->somebody_died)
		put_msg(t, id, ANSI_COLOR_YELLOW, "is thinking");
	pthread_mutex_unlock(&vars()->somebody_died_lock);
}

void	msg_die(uint64_t t, long id)
{
	pthread_mutex_lock(&vars()->somebody_died_lock);
	if (!vars()->somebody_died)
	{
		vars()->somebody_died = 1;
		put_msg(t, id, ANSI_COLOR_RED, "died");
	}
	pthread_mutex_unlock(&vars()->somebody_died_lock);
}
