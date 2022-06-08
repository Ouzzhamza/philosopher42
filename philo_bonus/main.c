/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:26:23 by houazzan          #+#    #+#             */
/*   Updated: 2022/05/22 14:21:20 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/* **************************************************** */
/*                    🅵🅸🅻_🅸🅽🅵🅾                     */
/* **************************************************** */
int	init_semaphore(t_info *rules)
{
	sem_unlink("/philosopher_write");
	sem_unlink("/philosopher_forks");
	sem_unlink("/philosopher_dead");
	rules->write = sem_open("/philosopher_write", O_CREAT, \
		S_IRUSR | S_IWUSR, 1);
	rules->forks = sem_open("/philosopher_forks", O_CREAT, \
		S_IRUSR | S_IWUSR, rules->philo_number);
	if (rules->forks == SEM_FAILED || rules->write == SEM_FAILED)
		return (1);
	return (0);
}

/* **************************************************** */
/*                    🅵🅸🅻_🅸🅽🅵🅾                     */
/* **************************************************** */

int	init_philo(t_info *rules, t_philosopher *philosopher)
{
	int	i;

	i = 0;
	while (i < rules->philo_number)
	{
		philosopher[i].rules = rules;
		philosopher[i].id = i;
		philosopher[i].right_fork_id = i;
		philosopher[i].left_fork_id = (i + 1) % rules->philo_number;
		philosopher[i].last_meal_time = 0;
		philosopher[i].n_ate = 0;
		i++;
	}
	return (1);
}

/* **************************************************** */
/*                     🅶🅴🆃_🅸🅽🅵🅾                    */
/* **************************************************** */

int	get_info(int ac, char **av, t_info *rules, t_philosopher *philosopher)
{
	rules->philo_number = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->all_ate = 0;
	rules->died = 0;
	if (rules->time_to_die < 0 || rules->philo_number < 1 || \
		rules->time_to_sleep < 0 || rules->time_to_sleep < 0)
		return (0);
	if (ac == 6)
	{
		rules->number_of_meals = ft_atoi(av[5]);
		if (rules->number_of_meals <= 0)
			return (0);
	}
	else
		rules->number_of_meals = -1;
	init_semaphore(rules);
	init_philo(rules, philosopher);
	return (1);
}

/* **************************************************** */
/*                        🅼🅰🅸🅽                       */
/* **************************************************** */

int	main(int ac, char **av)
{
	t_info			rules;
	t_philosopher	*philosopher;

	philosopher = NULL;
	if (ac != 5 && ac != 6)
		return (ft_error("Number of argument is wrong"));
	philosopher = (t_philosopher *) malloc \
	(ft_atoi(av[1]) * sizeof(t_philosopher));
	if (!get_info(ac, av, &rules, philosopher))
		return (ft_error("Problemes In Information"));
	start (&rules, philosopher);
	return (0);
}
