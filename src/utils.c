/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 04:19:41 by gbaud             #+#    #+#             */
/*   Updated: 2020/11/28 04:27:36 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/global.h"

char *join(char* s1, char* s2, int i)
{
    char* result = malloc(strlen(s1) + strlen(s2) + 1);
    if (result)
    {
        strcpy(result, s1);
        strcat(result, s2);
    }
	if (i == 1 || i == 3)
		free(s1);
	if (i == 2 || i == 3)
		free(s2);
    return result;
}