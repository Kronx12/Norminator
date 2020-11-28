/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 02:28:14 by gbaud             #+#    #+#             */
/*   Updated: 2020/11/28 05:00:03 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/global.h"

int     put_error(char *error)
{
    printf("\033[%d;%dm%s\n\033[%d;%dm", BOLD, RED, error, RESET, RESET);
    return (EXIT_FAILURE);
}

int     put_warning(char *warning)
{
    printf("\033[%d;%dm%s\n\033[%d;%dm", BOLD, YELLOW, warning, RESET, RESET);
    return (EXIT_SUCCESS);
}

int     put_success(char *success)
{
    printf("\033[%d;%dm%s\n\033[%d;%dm", BOLD, GREEN, success, RESET, RESET);
    return (EXIT_SUCCESS);
}