/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:29:30 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/11 08:21:32 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosophers.h"

int
	msleep_until_die(uint64_t t, long id)
{
	uint64_t	now;
	uint64_t	dest;

	if (get_current_time(&now))
		return (1);
	dest = now + t;
	while (now < dest)
	{
		if (vars()->somebody_died || is_finished(id))
			return (0);
		if (get_current_time(&now))
			return (1);
		if (usleep(500))
			return (print_and_return_code(1, "usleep error!"));
	}
	return (0);
}

int
	msleep(uint64_t t)
{
	uint64_t	now;
	uint64_t	dest;

	if (get_current_time(&now))
		return (1);
	dest = now + t;
	while (now < dest)
	{
		if (vars()->somebody_died)
			return (0);
		if (get_current_time(&now))
			return (1);
		if (usleep(500))
			return (print_and_return_code(1, "usleep error!"));
	}
	return (0);
}

int
	get_current_time(uint64_t *t)
{
	struct timeval	current;
	int				result;

	result = gettimeofday(&current, NULL);
	if (result)
	{
		*t = 0;
		return (print_and_return_code(1, "gettimeofday failed"));
	}
	*t = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (0);
}
