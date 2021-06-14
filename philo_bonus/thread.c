/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:46:51 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/11 08:47:08 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philosophers.h"

int
	tc(pthread_t *thread, void *(*func)(void *), void *arg, const char *fail)
{
	int	ret;

	ret = pthread_create(thread, NULL, func, arg);
	if (ret && fail && fail[0])
		printf("%s\n", fail);
	return (ret);
}

int
	td(pthread_t thread, const char *fail)
{
	int	ret;

	ret = pthread_detach(thread);
	if (ret && fail && fail[0])
		printf("%s\n", fail);
	return (ret);
}

int
	tj(pthread_t thread, void **res, const char *fail)
{
	int	ret;

	ret = pthread_join(thread, res);
	if (ret && fail && fail[0])
		printf("%s\n", fail);
	return (ret);
}
