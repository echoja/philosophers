/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:32:10 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/12 09:45:13 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include "philosophers.h"

int
	su(char *name, char *msg)
{
	if (sem_unlink(name))
		return (print_and_return_code(1, msg));
	return (0);
}

int
	sc(sem_t *sem, char *msg)
{
	if (sem_close(sem))
		return (print_and_return_code(1, msg));
	return (0);
}

int
	sw(sem_t *sem, char *msg)
{
	if (sem_wait(sem))
		return (print_and_return_code(1, msg));
	return (0);
}

int
	sp(sem_t *sem, char *msg)
{
	if (sem_post(sem))
		return (print_and_return_code(1, msg));
	return (0);
}
