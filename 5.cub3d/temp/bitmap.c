/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namkyu <namkyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:50:31 by namkyu            #+#    #+#             */
/*   Updated: 2021/04/08 21:20:42 by namkyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void bitmap_header(t_bmheader *header, int width, int height)
{
	int size;

	size = 4 * width * height;
	header->Type1 = 'B';
	header->Type2 = 'M';
	header->fSize = 54 + size;
	header->Reserved1 = 0;
	header->Reserved2 = 0;
	header->OffBits = 54;
	header->iSize = 40;
	header->Width = width;
	header->Height = -height;
	header->Planes = 1;
	header->BitCount = 32;
	header->Compression = 0;
	header->SizeImage = size;
	header->XPelsPerMeter = width;
	header->YPelsPerMeter = height;
	header->ClrUsed = 0xffffff;
	header->ClrImportant = 0;
}

void bitmap_create(t_data *data)
{
	t_bmheader header;
	int fd;
	int width;
	int height;
	int i;
	int j;

	width = data->resolution_width;
	height = data->resolution_height;
	if ((fd = open("screenshot.bmp", O_RDWR | O_TRUNC | O_CREAT, 0666)) < 0)
		exit_process(data, CANT_OPEN_FILE + 1);
	bitmap_header(&header, width, height);
	write(fd, &header, 54);
	i = -1;
	while (++i <= height)
	{
		j = -1;
		while (++j < width)
			write(fd, &data->img.data[i * data->img.size_l / 4 + j], 4);
	}
	close(fd);
}