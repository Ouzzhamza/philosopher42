/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houazzan <houazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:19:09 by houazzan          #+#    #+#             */
/*   Updated: 2022/04/23 15:35:07 by houazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <philosopher.h>

long long get_time(void)

{
    struct timeval time;
    
    gettimeofday(&time, NULL);
    return ((time.tv_sec * 1000) + (time.tv_usec * 1000));
    
}