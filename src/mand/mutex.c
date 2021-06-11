/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 09:58:41 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/11 08:47:13 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philosophers.h"

int
	mi(pthread_mutex_t *mutex, const char *fail)
{
	int	ret;

	ret = pthread_mutex_init(mutex, NULL);
	if (ret && fail && fail[0])
		printf("%s\n", fail);
	return (ret);
}

int
	ml(pthread_mutex_t *mutex, const char *fail)
{
	int	ret;

	ret = pthread_mutex_lock(mutex);
	if (ret && fail && fail[0])
		printf("%s\n", fail);
	return (ret);
}

int
	mul(pthread_mutex_t *mutex, const char *fail)
{
	int	ret;

	ret = pthread_mutex_unlock(mutex);
	if (ret && fail && fail[0])
		printf("%s\n", fail);
	return (ret);
}
