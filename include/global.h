/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 02:30:18 by gbaud             #+#    #+#             */
/*   Updated: 2020/11/28 04:43:34 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define RED 31
# define YELLOW 33
# define GREEN 32
# define BOLD 1
# define RESET 0

int		parse_file(int fd);
int		put_error(char *error);
int		put_warning(char *warning);
int		put_success(char *success);
char	*join(char* s1, char* s2, int i);

#endif