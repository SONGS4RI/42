#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct s_zone
{
	int		w;
	int		h;
	char	background;
} t_zone;

typedef struct s_shape
{
	char	type;
	float	x;
	float	y;
	float	r;
	char	color;
} t_shape;

int ft_strlen(char *str)
{
	int cnt = 0;
	while (str[cnt]) cnt++;
	return cnt;
}

int print_error(char *msg)
{
	write(1, msg, ft_strlen(msg));
	return(1);
}

int get_zone(FILE *file, t_zone *zone)
{
	if (fscanf(file, "%d %d %c\n", &zone->w, &zone->h, &zone->background) != 3)
		return 1;
	if (zone->w <= 0 || zone->w > 300 || zone->h <= 0 || zone->h > 300)
		return 1;
	return 0;
}

char *draw_back(t_zone *zone)
{
	char *res;
	if ((res = (char *)malloc(sizeof(char) * zone->w * zone->h)) == NULL) return NULL;
	memset(res, zone->background, zone->w * zone->h);
	return res;
}

void print_res(t_zone *zone, char *res)
{
	for(int i=0;i<zone->h;i++)
	{
		for(int j=0;j<zone->w;j++) write(1, &res[i * zone->w + j], 1);
		write(1, "\n", 1);
	}
}

int is_it(float x, float y, t_shape shape)
{
	float dist = sqrtf(powf(shape.x - x ,2.0) + powf(shape.y - y ,2.0));
	if (dist > shape.r) return 0;
	if (dist > shape.r - 1.0000) return 1;
	return 2;
}

void draw_shape(t_zone *zone, t_shape shape, char *drawing)
{
	int ret;

	for(int i=0;i<zone->h;i++)
	{
		for(int j=0;j<zone->w;j++)
		{
			ret = is_it(j, i, shape);
			if ((ret == 1 && shape.type == 'c') || (ret && shape.type == 'C'))
				drawing[i * zone->w + j] = shape.color;
		}
	}
}

int draw_shapes(FILE *file, t_zone *zone, char *drawing)
{
	int 	ret;
	t_shape shape;
	while ((ret = fscanf(file, "%c %f %f %f %c\n", \
	&shape.type, &shape.x, &shape.y, &shape.r, &shape.color) == 5))
	{
		if (shape.r <= 0.0000000 || (shape.type != 'c' && shape.type != 'C')) return 1;
		draw_shape(zone, shape, drawing);
	}
	if (ret == -1) return 1;
	return 0;
}

int main(int ac, char **av)
{
	FILE *file;
	t_zone zone;
	char *drawing;

	if (ac != 2) return (print_error("Error: argument\n"));
	if (!(file = fopen(av[1], "r"))) return (print_error("Error: Operation file corrupted\n"));
	if (get_zone(file, &zone)) return (print_error("Error: zone\n"));
	if (!(drawing = draw_back(&zone))) return (print_error("Error: malloc\n"));
	if (draw_shapes(file, &zone, drawing)) return (print_error("Error: shape\n"));
	print_res(&zone, drawing);
}