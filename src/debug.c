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

//typedef union   s_test
//{
//    unsigned    x32;
//    char        c[4];
//}               t_test;

void				print_buf(t_control *control)
{
	unsigned char    *tmp;

	tmp = (unsigned char*)control->buf;
	for (int k = 0; k < 64; k++) {
        if (k && !(k%4))
            printf(" ");
        printf("%.2x", tmp[k]);
    }
	printf("\n");
}

void				print_int(unsigned int i)
{
	unsigned char    *tmp;

	tmp = (unsigned char*)&i;
	for (int k = 0; k < 4; k++) {
		printf("%.2x", tmp[k]);
	}
}

void print_buf2(t_control *control)
{
	for (int i = 0; i < 16; i++)
	{
		print_int(control->buf[i]);
		if (i != 15)
			printf(" ");
	}
	printf("\n");
}