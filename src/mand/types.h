/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 11:00:23 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/10 09:55:31 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <sys/time.h>
# include <sys/types.h>
# include <stdint.h>
# include <pthread.h>

typedef struct timeval	t_timeval;

typedef struct s_vars	t_vars;

struct	s_vars
{
	long			nop;
	long			ttd;
	long			tte;
	long			tts;
	long			notepme;
	long			*remained_times;
	long			*available_forks;
	long			somebody_died;
	pthread_mutex_t	somebody_died_lock;
	pthread_mutex_t	*locks;
	pthread_mutex_t even_first_lock;
	uint64_t		*recent_meal;
	uint64_t		start;
	pthread_mutex_t	once;
	pthread_t		*philos;
	long			philo_count;
	pthread_t		*watchers;
	const char		*color[6];
};

#endif
