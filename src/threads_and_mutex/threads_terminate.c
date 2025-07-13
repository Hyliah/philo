/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_terminate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:29:15 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/13 19:22:23 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//fonction de detach a gerer, tester etc.. c est une premiere mise en place.

// int	detach_one_thread(t_thread *thread)
// {
// 	int  ret;

// 	ret = pthread_detach(thread);
// 	if (ret)
// 		printf("%d\n", ret); //faire une meilleure gestion de ca
// 	return (ret);
// }

// int	detach_all(t_philo *philo)
// {
// 	int	i;
// 	int	ret;

// 	i = 0;
// 	while (i < philo->parsing.nb_philo)
// 	{
// 		ret = detach_one_thread(&philo->thread[i]);
// 		i++;
// 		if (ret)
// 			return (i); // pas sure de ca mais a voir.
// 	}
// 	return (ret);
// }

// int	detach_mid_creation(t_philo *philo, int nb)
// {
// 	int	i;
// 	int	ret;

// 	i = 0;
// 	while (i < nb)
// 	{
// 		ret = detach_one_thread(&philo->thread[i]);
// 		i++;
// 		if (ret)
// 			return (i); // pas sure de ca mais a voir. comme pour plus haut
// 	}
// 	return (ret);
// }

/*
NAME
	pthread_detach – detach a thread

SYNOPSIS
	#include <pthread.h>

	int
	pthread_detach(pthread_t thread);

DESCRIPTION
	The pthread_detach() function is used to indicate to the implementation
    that storage for the thread thread can be reclaimed when the thread 
    terminates. If thread has not terminated, pthread_detach() will not 
    cause it to terminate. The effect of multiple pthread_detach() calls on 
    the same target thread is unspecified.

RETURN VALUES
	If successful, the pthread_detach() function will return zero.  
	Otherwise an error number will be returned to indicate the error.  
	Note that the function does not change the value of errno as it did 
	for some drafts of the standard.
	These early drafts also passed a pointer to pthread_t as the argument.
	Beware!

ERRORS
	The pthread_detach() function will fail if:

	[EINVAL]           The implementation has detected that the value specified 
				    by thread does not refer to a joinable thread.

	[ESRCH]            No thread could be found corresponding to that specified 
				    by the given thread ID, thread.
*/