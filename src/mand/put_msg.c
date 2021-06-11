/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:52:11 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/11 06:39:13 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void
	put_msg(uint64_t t, long id, const char *color, const char *msg)
{
	int	color_index;

	color_index = id % 6;
	t = t - vars()->start;
	printf("%10lld %s%03ld" ANSI_COLOR_RESET " %s%s\n" ANSI_COLOR_RESET, t,
		vars()->color[color_index], id + 1, color, msg);
}
