/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:44:59 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/11 08:45:09 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void
	*watch_thread(void *arg)
{
	long		id;
	long		remained_times;
	uint64_t	t;

	id = (long)arg;
	remained_times = vars()->remained_times[id];
	msleep_until_die(vars()->ttd, id);
	if (vars()->remained_times[id] == remained_times && !is_finished(id))
	{
		get_current_time(&t);
		die(id, t, 0);
	}
	return ((void *)0);
}
