/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:09:55 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/12 09:31:28 by taehokim         ###   ########.fr       */
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
	safe_free(&vars()->remained_times);
	safe_free(&vars()->philos);
	safe_free(&vars()->pid);
	safe_free(&vars()->recent_meal);
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
