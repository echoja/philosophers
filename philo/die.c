/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:02:05 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/07 19:09:15 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include "philosophers.h"

long
	die(long id, uint64_t now, uint64_t after)
{
	if (after)
		msleep(after);
	msg_die(now + after, id);
	return (0);
}
