/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:37:52 by hlichten          #+#    #+#             */
/*   Updated: 2025/07/13 17:37:57 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_start_time(t_philo *philo)
{
	struct timeval	*tv;

	(void)philo;
	tv = malloc(sizeof(struct timeval));
	if (gettimeofday(tv, NULL) != 0)
		return ; // faire une sortie du projet un peu correct
	pthread_mutex_lock(&philo->mutex.print_lock);
	printf ("%ld that s time\n", tv->tv_sec);
	pthread_mutex_unlock(&philo->mutex.print_lock);
}

// NAME
//        gettimeofday, settimeofday - get / set time

// SYNOPSIS
//        #include <sys/time.h>

//        int gettimeofday(struct timeval *tv, struct timezone *tz);

//        int settimeofday(const struct timeval *tv, const struct timezone *tz);

//    Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

//        settimeofday():
//            Since glibc 2.19:
//                _DEFAULT_SOURCE
//            Glibc 2.19 and earlier:
//                _BSD_SOURCE

// DESCRIPTION
//        The functions gettimeofday() and settimeofday() can get and set the time as well as a timezone.

//        The tv argument is a struct timeval (as specified in <sys/time.h>):

//            struct timeval {
//                time_t      tv_sec;     /* seconds */
//                suseconds_t tv_usec;    /* microseconds */
//            };

//        and gives the number of seconds and microseconds since the Epoch (see time(2)).

//        The tz argument is a struct timezone:

//            struct timezone {
//                int tz_minuteswest;     /* minutes west of Greenwich */
//                int tz_dsttime;         /* type of DST correction */
//            };

//        If either tv or tz is NULL, the corresponding structure is not set or returned.  (However, compilation warnings will result if tv is NULL.)

//        The use of the timezone structure is obsolete; the tz argument should normally be specified as NULL.  (See NOTES below.)

//        Under  Linux, there are some peculiar "warp clock" semantics associated with the settimeofday() system call if on the very first call (after booting) that has a non-NULL tz argument, the tv argument is NULL and the tz_minuteswest field is nonzero.  (The tz_dsttime field should be zero for this
//        case.)  In such a case it is assumed that the CMOS clock is on local time, and that it has to be incremented by this amount to get UTC system time.  No doubt it is a bad idea to use this feature.

// RETURN VALUE
//        gettimeofday() and settimeofday() return 0 for success, or -1 for failure (in which case errno is set appropriately).

// ERRORS
//        EFAULT One of tv or tz pointed outside the accessible address space.

//        EINVAL (settimeofday()): timezone is invalid.

//        EINVAL (settimeofday()): tv.tv_sec is negative or tv.tv_usec is outside the range [0..999,999].

//        EINVAL (since Linux 4.3)
//               (settimeofday()): An attempt was made to set the time to a value less than the current value of the CLOCK_MONOTONIC clock (see clock_gettime(2)).

//        EPERM  The calling process has insufficient privilege to call settimeofday(); under Linux the CAP_SYS_TIME capability is required.
