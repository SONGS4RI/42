#include "../cub3d.h"

t_vector	get_vector(int x, int y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector	get_rotated_vector(t_vector origin, double angle)
{
	t_vector	result;
	double		sin_value;
	double		cos_value;

	sin_value = sin(angle);
	cos_value = cos(angle);
	result.x = cos_value * origin.x - sin_value * origin.y;
	result.y = sin_value * origin.x + cos_value * origin.y;
	return (result);
}
