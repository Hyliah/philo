/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_terminate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:29:15 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/11 00:41:55 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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