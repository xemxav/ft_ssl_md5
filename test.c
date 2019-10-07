
#include "includes/ft_ssl.h"
#include "libft/libft.h"

void increment_i(int *i)
{
	*i = *i++;
}

int main()
{
	int i =0;
	increment_i(&i);
	ft_printf("%d\n", i);
	return(0);
}