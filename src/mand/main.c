/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:21:31 by taehokim          #+#    #+#             */
/*   Updated: 2021/06/11 08:59:45 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long
	check_if_num(const char *s)
{
	long	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long
	chars_to_long(const char *s)
{
	long	result;
	long	i;

	result = 0;
	i = 0;
	while (s[i])
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result);
}

void
	parse_args(char *argv[], int has_notepme)
{
	vars()->nop = chars_to_long(argv[1]);
	vars()->ttd = chars_to_long(argv[2]);
	vars()->tte = chars_to_long(argv[3]);
	vars()->tts = chars_to_long(argv[4]);
	if (has_notepme)
	{
		vars()->notepme = chars_to_long(argv[5]);
	}
}

int
	main(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (print_and_return_code(1, "invalid params\nusage: philo number"
		"_of_philo time_to_die time_to_eat time_to_sleep"
		" [number_of_times_each_philosopher_must_eat]"));
	if (!check_if_num(argv[1]) || !check_if_num(argv[2]) ||
		!check_if_num(argv[3]) || !check_if_num(argv[4]))
		return (print_and_return_code(1, "Invalid param: number "
		"should be positive integer"));
	if (argc == 6 && !check_if_num(argv[5]))
		return (print_and_return_code(1, "Invalid param: number "
		"should be positive integer"));
	parse_args(argv, argc == 6);
	if (vars()->nop == 0 || vars()->ttd == 0 || vars()->tte == 0 ||
		vars()->tts == 0 || (argc == 6 && vars()->notepme == 0))
		return (print_and_return_code(1, "Invalid param: number "
		"should be positive integer"));
	if (vars()->nop <= 1)
		return (print_and_return_code(1, "philo must be more than 1"));
	start_philo_one();
}
