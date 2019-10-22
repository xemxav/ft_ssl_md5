#include "../includes/ft_ssl.h"

void	print_control(t_control *control)
{
	ft_printf("control->hash = %s\n", control->hash);
	ft_printf("control->message = %s\n", control->message);
	ft_printf("control->p = %d\n", control->p);
	ft_printf("control->q = %d\n", control->q);
	ft_printf("control->r = %d\n", control->r);
	ft_printf("control->file_only = %d\n", control->file_only);
	ft_printf("control->type = %d\n\n", control->type);
}

void				print_buf(t_control *control)
{
	int i = 0;
	while (i < 16)
	{
		printf("%#x ", control->buf[i]);
		i++;
	}
	printf("\n");
}