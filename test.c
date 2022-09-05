#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int	ft_find_next_prime(int nb)
{
	int	i;
	int	flag;

	while (1)
	{
		i = 2;
		flag = 1;
		while (i <= nb / i)
		{
			if (nb % i == 0)
			{
				flag = 0;
				break ;
			}
			i++;
		}
		if (flag == 0)
			nb++;
		else
			return (nb);
	}
}

////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int num = INT32_MAX-20;

	printf("%d\n",ft_find_next_prime(num));

}