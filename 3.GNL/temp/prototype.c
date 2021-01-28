/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlee <nlee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:06:30 by nlee              #+#    #+#             */
/*   Updated: 2020/11/18 16:36:15 by nlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

int		get_next_line(int fd, char **line)
{
	static char **line_storage[OPEN_MAX];
	char buff[BUFFER_SIZE + 1];
	int read_len;

	while(1)
	{
		memset(buff, 0, BUFFER_SIZE + 1);
		read_len = read(fd, buff, BUFFER_SIZE);
		line_storage[fd] = ft_strjoin(line_storage[fd],buff);
		if (is_newline(line_storage) || read_len == 0)
			return(trim(line_storage))
	}
}
