/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 02:26:22 by gbaud             #+#    #+#             */
/*   Updated: 2020/11/28 05:27:19 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/global.h"

int is_c_file(char *file)
{
    return (file[strlen(file) - 2] == '.' && (file[strlen(file) - 1] == 'c' || file[strlen(file) - 1] == 'h'));
}

int main(int ac, char **av)
{
    int fd;
    char *out;
    struct stat st = {0};

    if (ac < 3)
        exit(put_error("file is missing: usage: ./norminator [file1 ... fileN] [output_dir]"));
    if (stat(av[ac - 1], &st) == -1)
        mkdir(av[ac - 1], 0700);
    for (int i = 1; i < ac - 1; ++i)
        if (is_c_file(av[i]))
        {
            fd = open(av[i], O_RDONLY);
            if (parse_file(fd) == -1)
            {
                out = join("[", av[i], 0);
                out = join(out, "] can't be open or error when read (check permissions)", 1);
                put_error(out);
                free(out);
            }
            else
                put_success(av[i]);
        }
        else
        {
            out = join("[", av[i], 0);
            out = join(out, "] not c/h file", 1);
            put_warning(out);
            free(out);
        }
    return (0);
}