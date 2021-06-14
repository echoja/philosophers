/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:44:36 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/14 19:53:50 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philosophers.h"

void	msg_take_fork(uint64_t t, long id)
{
	sw(vars()->msg_sem, "msg_sem wait failed");
	if (!is_somebody_died())
	{
		put_msg(t, id, ANSI_COLOR_BLUE, "has taken a fork");
		put_msg(t, id, ANSI_COLOR_BLUE, "has taken a fork");
	}
	sp(vars()->msg_sem, "msg_sem wait failed");
}

void	msg_eat(uint64_t t, long id)
{
	sw(vars()->msg_sem, "msg_sem wait failed");
	if (!is_somebody_died())
		put_msg(t, id, ANSI_COLOR_CYAN, "is eating");
	sp(vars()->msg_sem, "msg_sem wait failed");
}

void	msg_sleep(uint64_t t, long id)
{
	sw(vars()->msg_sem, "msg_sem wait failed");
	if (!is_somebody_died())
		put_msg(t, id, ANSI_COLOR_MAGENTA, "is sleeping");
	sp(vars()->msg_sem, "msg_sem wait failed");
}

void	msg_think(uint64_t t, long id)
{
	sw(vars()->msg_sem, "msg_sem wait failed");
	if (!is_somebody_died())
		put_msg(t, id, ANSI_COLOR_YELLOW, "is thinking");
	sp(vars()->msg_sem, "msg_sem wait failed");
}

void	msg_die(uint64_t t, long id)
{
	sw(vars()->msg_sem, "msg_sem wait failed");
	if (!is_somebody_died())
	{
		put_msg(t, id, ANSI_COLOR_RED, "died");
		su(SN_DIED, "died unlink failed");
		exit(0);
	}
	sp(vars()->msg_sem, "msg_sem wait failed");
}
