
#include "includes/ft_ssl.h"
#include "libft/libft.h"

void                *ft_memrev(void *block, size_t elsize, size_t elnum)
{
	size_t          i;
	unsigned char *tmp;

	i = 0;
	tmp = (unsigned char*)malloc(sizeof(unsigned char) * elsize);
	if (!tmp)
		return (NULL);
	while (i <= elnum - 1)
	{
		tmp = (unsigned char*)malloc(sizeof(unsigned char) * elsize);
		if (!tmp)
			return (NULL);
		ft_memmove(tmp,  block + (elsize * (elnum - 1)), elsize);
		//le premier dans le dernier
		ft_memmove(block + (elsize * (elnum - 1)), block + (i * elsize), elsize);
		//tmp das le premier
		ft_memmove(block + (i * elsize), tmp, elsize);

		elnum--;
		ft_bzero((void*)tmp, sizeof(unsigned char) * elsize);
		i++;
	}
	free(tmp);
	return (block);
}

int main()
{
	int i[3] = {1,2,3};
	ft_memrev((void*)&i, sizeof(int), 3);
	printf("%d ", i[0]);
	printf("%d ", i[1]);
	printf("%d ", i[2]);
	return(0);
}