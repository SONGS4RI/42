#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_zone
{
	int		width;
	int		height;
	char	background;
}	t_zone;

typedef struct s_shape
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;
}	t_shape;

int	clear_all(FILE *file, t_zone *zone, char **drawing)
{
	fclose(file);
	if (drawing)
	{
		for(int i=0;i<zone->height;i++) free(drawing[i]);
		free(drawing);
	}
	return (1);
}

int ft_strlen(char *str)
{
	int idx = 0;
	if (!str) return (0);
	while (str[idx])
		idx++;
	return (idx);
}

int print_err(char *message)
{
	write(1, message, ft_strlen(message));
	return (1);
}

int	check_zone(t_zone *zone)
{
	return (zone->width > 0 && zone->width <= 300 && zone->height > 0 && zone->height <= 300);
}

int	get_zone(FILE *file, t_zone *zone)
{
	int	scan_ret;

	if ((scan_ret = fscanf(file, "%d %d %c", &zone->width, &zone->height, &zone->background)) != 3)
		return (1);
	if (!check_zone(zone))
		return (1);
	if (scan_ret == -1)
		return (1);
	return (0);
}

char	**paint_background(t_zone *zone)
{
	char	**drawing;
	char	*row;
	int		i;

	drawing = (char **)malloc(sizeof(char *) * (zone->height));
	for(int i=0;i<zone->height;i++)
	{
		row = (char *)malloc(sizeof(char) * (zone->width));
		memset(row, zone->background, sizeof(char) * (zone->width));
		drawing[i] = row;
	}
	return drawing;
}

int	check_shape(t_shape *shape)
{
	return (shape->width > 0.00000000 && shape->height > 0.00000000 \
	&& (shape->type == 'r' || shape->type == 'R'));
}

int	in_rectangle(float x, float y, t_shape *shape)
{
	if (x < shape->x || x > shape->x + shape->width \
	|| y < shape->y || shape->y + shape->height < y)
		return (0);
	if (x - shape->x < 1.00000000 || x > shape->x + shape->width - 1.00000000 \
	|| y - shape->y < 1.00000000 || y > shape->y + shape->height - 1.00000000)
		return (1);
	return (2);
}

void draw_shape(char **drawing, t_shape *shape, t_zone *zone)
{
	int ret;

	for(int i=0;i<zone->height;i++)
	{
		for(int j=0;j<zone->width;j++)
		{
			ret = in_rectangle(j,i,shape);
			if ((shape->type == 'r' && ret == 1) || (shape->type == 'R' && ret))
				drawing[i][j] = shape->color;
		}
	}
}

int	draw_shapes(FILE *file, char **drawing, t_zone *zone)
{
	t_shape	tmp;
	int		scan_ret;

	while ((scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.width, &tmp.height, &tmp.color)) == 6)
	{
		if (!check_shape(&tmp))
			return (1);
		draw_shape(drawing, &tmp, zone);
	}
	if (scan_ret == -1) return (1);
	return (0);
}

void	draw_drawing(t_zone *zone,char **drawing)
{
	for(int i=0;i<zone->height;i++)
	{
		for(int j=0;j<zone->width;j++) write(1, &drawing[i][j], 1);
		write(1, "\n", 1);
	}
}

void leaks(void)
{
	system("leaks a.out");
}

int main(int argc, char **argv)
{
	FILE	*file;
	t_zone	zone;
	char	**drawing;

	atexit(leaks);
	if (argc != 2)
		return (print_err("Error: argument\n"));
	if (!(file = fopen(argv[1], "r")))
		return (print_err("Error: Operation file corrupted\n"));
	if (get_zone(file, &zone))
		return (clear_all(file, &zone, NULL) && print_err("Error: Operation file corrupted\n"));
	drawing = paint_background(&zone);
	if (draw_shapes(file, drawing, &zone))
		return (clear_all(file, &zone, drawing) && print_err("Error: Operation file corrupted\n"));
	draw_drawing(&zone, drawing);
	clear_all(file, &zone, drawing);
}