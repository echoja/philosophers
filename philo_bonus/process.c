/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:03:10 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/14 20:23:09 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "pthread.h"
#include "philosophers.h"

int
	tc_step_2(long init_i)
{
	long	id;

	if (ml(&vars()->even_first_lock, "efl lock failed"))
		return (1);
	id = init_i;
	while (id < vars()->nop)
	{
		vars()->pid[id] = fork();
		if (vars()->pid[id] == -1)
			return (print_and_return_code(1, "philo process create failed"));
		if (vars()->pid[id] == 0)
		{
			if (do_philo_one((void *)id) != (void *)0)
				exit(1);
			exit(0);
		}
		id += 2;
	}
	if (mul(&vars()->even_first_lock, "efl unlock failed"))
		return (1);
	return (0);
}

void
	wait_subprocesses(long init_i, long finish_count)
{
	long	i;
	int		status;
	int		res;
	long	success_count;
	sem_t	*imsi_sem;

	i = init_i;
	success_count = 0;
	while (i < vars()->nop)
	{
		res = waitpid(vars()->pid[i], &status, WNOHANG);
		if (so_weak(&imsi_sem, SN_DIED, ""))
			break ;
		else if (res != 0)
			success_count++;
		if (success_count == finish_count)
			break ;
		usleep(10000);
		i += 2;
		if (i >= vars()->nop)
			i -= vars()->nop;
	}
}

void
	kill_subprocesses(void)
{
	int	i;

	i = 0;
	while (i < vars()->nop)
	{
		kill(vars()->pid[i], SIGINT);
		i++;
	}
}
