#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_obj
{
	char type;
	float x;
	float y;
	float w;
	float h;
	char c;
}				t_obj;

typedef struct s_canvas
{
	char **pix;
	int w;
	int h;
	char c;
}				t_canvas;

int print_arg_err(void)
{
	int i;

	i = 0;
	write(1,"Error: argument\n", 16);
	return (1);
}

int print_oper_err(t_canvas *canvas)
{
	int i;

	i = 0;
	write(1,"Error: Operation file corrupted\n", 32);
	while (canvas->pix[i])
	{
		free(canvas->pix[i]);
		i++;
	}
	free(canvas->pix);
	return (1);
}

void input_canvas(t_obj *obj, t_canvas *canvas)
{
	int i;
	int j;

	i = 0;
	while (i < canvas->h)
	{
		j = 0;
		while (j < canvas->w)
		{
			// 1. border rec
			// 2. inner rec
			if ((int)(obj->x + 1) == j || \
			(int)(obj->x + obj->w) == j || \
			(int)(obj->y + 1) == i || \
			(int)(obj->y + obj->h) == i)
				canvas->pix[i][j] = obj->c;
			else if ((obj->type == 'R') && \
			(j > obj->x && j < obj->x + obj->w) && \
			(i > obj->y && i < obj->y + obj->h))
				canvas->pix[i][j] = obj->c;
			j++;
		}
		i++;
	}
}

int parse_object_is_valid(FILE *fp, t_canvas *canvas)
{
	int scan;
	t_obj obj;

	while ((scan = fscanf(fp, "%c %f %f %f %f %c\n", &obj.type, &obj.x, &obj.y, &obj.w, &obj.h, &obj.c)) == 6)
	{
		if ((obj.w <= 0 ) || \
			(obj.h <= 0 ) || \
			!((obj.type == 'r') || (obj.type == 'R')))
			return (0);
		input_canvas(&obj, canvas);
	}
	if (scan == EOF)
		return (1);
	return (0);
}

int parse_canvas_is_valid(FILE *fp, t_canvas *canvas)
{
	int scan;
	int i;

	if ((scan = fscanf(fp, "%d %d %c\n", &canvas->w, &canvas->h, &canvas->c)) != 3)
		return (0);
	if ((canvas->w >300 || canvas->w <= 0) || (canvas->h > 300 || canvas->h <= 0))
		return (0);
	if (scan == EOF)
		return (0);
	if (!(canvas->pix = (char **)malloc(sizeof(char *) * (canvas->h + 1))))
		return (0);
	i = 0;
	while (i < canvas->h)
	{
		if (!(canvas->pix[i] = (char *)malloc(sizeof(char) * (canvas->w + 1))))
			return (0);
		memset(canvas->pix[i], canvas->c, (sizeof(char) * (canvas->w + 1)));
		canvas->pix[i][canvas->w] = 0;
		i++;
	}
	canvas->pix[i] = NULL;
	return (1);
}

void print_canvas(t_canvas *canvas)
{
	int i;

	i = 0;
	while (canvas->pix[i])
	{
		printf("%s\n", canvas->pix[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	t_canvas canvas;
	FILE *fp;

	memset(&canvas, 0, sizeof(canvas));
	if (ac != 2)
		return (print_arg_err());
	if (!(fp = fopen(av[1], "r")))
		return (print_oper_err(&canvas));
	if (!(parse_canvas_is_valid(fp, &canvas)))
		return (print_oper_err(&canvas));
	if (!(parse_object_is_valid(fp, &canvas)))
		return (print_oper_err(&canvas));
	print_canvas(&canvas);
	return (0);
}