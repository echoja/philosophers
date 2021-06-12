/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:21:25 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/12 09:47:15 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define SN_FORKS "sem_forks"
# define SN_DIED "sem_died"
# define SN_MSG "sem_msg"

# define R_SOMEBODY_DIED 0
# define R_ERROR 1
# define R_BREAK 2
# define R_CONTINUE 3

# include "types.h"

# include <stdio.h>

int
init(void);

int
start_philo_one(void);

void
*start_philo_half(void *even);

void
*do_philo_one(void *arg);

int
philo_one_loop(long id, pthread_t *watcher);

t_vars
*vars(void);

/*
** resources
*/

int
print_and_return_code(int code, char *msg);

void
safe_free(void *target);

int
safe_exit(int code);

int
m(void *target, size_t size);

int
get_current_time(uint64_t *t);

int
so(sem_t **sem, char *name, unsigned int value, char *msg);

int
so_weak(sem_t **sem, char *name, char *msg);

int
sc(sem_t *sem, char *msg);

int
su(char *name, char *msg);

int
sw(sem_t *sem, char *msg);

int
sp(sem_t *sem, char *msg);

int
is_somebody_died(void);

int
tc_step_2(long init_i);

void
wait_subprocesses(long init_i);

void
kill_subprocesses(void);

/*
** msg
*/

void
put_msg(uint64_t t, long id, const char *color, const char *msg);

void
msg_take_fork(uint64_t t, long id);

void
msg_eat(uint64_t t, long id);

void
msg_sleep(uint64_t t, long id);

void
msg_think(uint64_t t, long id);

void
msg_die(uint64_t t, long id);

long
die(long id, uint64_t now, uint64_t after);

int
msleep(uint64_t t);

int
msleep_until_die(uint64_t t, long id);

int
is_finished(long id);

int
lock_near(void);

int
unlock_near(void);

int
philo_eat(long id);

int
philo_sleep(long id);

int
philo_think(long id);

void
*watch_thread(void *arg);

int
tc(pthread_t *thread, void *(*func)(void *), void *arg, const char *fail);

int
td(pthread_t thread, const char *fail);

int
tj(pthread_t thread, void **res, const char *fail);

int
mi(pthread_mutex_t *mutex, const char *fail);

int
ml(pthread_mutex_t *mutex, const char *fail);

int
mul(pthread_mutex_t *mutex, const char *fail);

#endif
