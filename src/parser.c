/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 04:30:57 by gbaud             #+#    #+#             */
/*   Updated: 2020/11/28 05:40:45 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/global.h"

void del(void *content) { free(content); }
void *f(void *node) { return (ft_strtrim(node, WHITESPACE)); }
int	parse_file(int fd)
{
	int r;
	char *line;
	t_list *head = NULL;
	do
	{
		r = get_next_line(fd, &line);
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	while (r > 0);
	t_list *trimmed = ft_lstmap(head, f, del);
	ft_lstclear(&head, del);
	
	ft_lstiter(trimmed, (void (*)(void *))put_warning);
	ft_lstclear(&trimmed, del);
	return (r);
}