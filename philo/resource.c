/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:09:55 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/11 10:48:53 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "philosophers.h"

int
	safe_exit(int code)
{
	long	i;

	i = -1;
	while (++i < vars()->nop)
		pthread_mutex_destroy(&vars()->locks[i]);
	pthread_mutex_destroy(&vars()->somebody_died_lock);
	safe_free(&vars()->locks);
	safe_free(&vars()->philos);
	safe_free(&vars()->recent_meal);
	safe_free(&vars()->remained_times);
	safe_free(&vars()->available_forks);
	return (code);
}

int
	print_and_return_code(int code, char *msg)
{
	if (msg && msg[0])
		printf("%s\n", msg);
	return (code);
}

int
	m(void *target, size_t size)
{
	void	**pt;

	pt = (void **)target;
	*pt = malloc(size);
	if (*pt == 0)
		return (0);
	return (1);
}

void
	safe_free(void *target)
{
	void	**pt;

	pt = (void **)target;
	if (*pt)
	{
		free(*pt);
		*pt = 0;
	}
}
