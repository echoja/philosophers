/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_open.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:44:53 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/12 09:46:50 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include "philosophers.h"

int
	so(sem_t **sem, char *name, unsigned int value, char *msg)
{
	sem_t	*ret;

	ret = sem_open(name, O_CREAT, 0644, value);
	if (ret == SEM_FAILED)
		return (print_and_return_code(1, msg));
	*sem = ret;
	return (0);
}

int
	so_weak(sem_t **sem, char *name, char *msg)
{
	sem_t	*ret;

	ret = sem_open(name, 0);
	if (ret == SEM_FAILED)
		return (print_and_return_code(1, msg));
	*sem = ret;
	return (0);
}
