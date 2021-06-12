/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:23:39 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/11 08:32:04 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

void *test_thread1(void *arg)
{
	printf("thread: %d\n", *(int *)arg);
	return (void *)(13241324);
}

void test_create_pthread()
{
	pthread_t threads[5];
	int done[5];
	int args[5];
	int rc;
	int status;

	for (int i = 0; i < 5; i++)
	{
		args[i] = i;
		done[i] = 0;
		pthread_create(&threads[i], NULL, &test_thread1, (void *)&args[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		done[i] = 1;
		rc = pthread_join(threads[i], (void **)&status);
		if (rc == 0)
		{
			printf("Completed join with thread %d status= %d\n", i, status);
		}
		else
		{
			printf("ERROR; return code from pthread_join() is %d, thread %d, %s\n", rc, i, strerror(rc));
			// return;
		}
	}
}

pthread_mutex_t g_mutex;

struct data1 {
	pthread_mutex_t mutex_lock;
	char			*str;
	int				num;
};

void *test_mutex_thread(void *data)
{
	struct data1 *dd = (struct data1 *)data;
	pthread_mutex_lock(&dd->mutex_lock);
	// pthread_mutex_lock(&g_mutex);
	dd->num += 1;
	pthread_mutex_unlock(&dd->mutex_lock);
	// pthread_mutex_unlock(&g_mutex);
	return (void *)1;
}

void test_mutex()
{
	pthread_t threads[5];
	struct data1 d;
	int status;
	int rc;

	d.str = "1234";
	d.num = 0;
	pthread_mutex_init(&d.mutex_lock, NULL);
	// pthread_mutex_init(&g_mutex, NULL);

	int done[5];
	int args[5];

	for (int i = 0; i < 5; i++)
	{
		args[i] = i;
		done[i] = 0;
		pthread_create(&threads[i], NULL, &test_mutex_thread, (void *)&d);
	}
	for (int i = 0; i < 5; i++)
	{
		done[i] = 1;
		rc = pthread_join(threads[i], (void **)&status);
		if (rc == 0)
		{
			printf("Completed join with thread %d status=%d, value=%d\n", i, status, d.num);
		}
		else
		{
			printf("ERROR; return code from pthread_join() is %d, thread %d, %s\n", rc, i, strerror(rc));
			// return;
		}
	}
}

void test_start_philo_one()
{
	vars()->nop = 4;
	vars()->ttd = 410;
	vars()->tte = 200;
	vars()->tts = 200;
	vars()->notepme = 0;
	start_philo_one();
}

int main(void)
{
	// test_set_init_time();
	// test_create_pthread();
	// test_mutex();
	test_start_philo_one();
	return (0);
}
