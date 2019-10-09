/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   md5.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 17:30:03 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 17:30:03 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int 		md5_hash(char *truc)
{
	return (ft_printf("je hash en md5 %s\n", truc));
}

int				md5(t_control *control, int ac, char **av)
{
	int 		c;
	t_parsing	pars;

	ft_bzero((void*)&pars, sizeof(t_parsing));
	pars.iac = 1;
	control->hash = ft_strdup("md5");
	if (ac == 1)
		return (md5_hash("stdin"));
	while (pars.iac < ac)
	{
		c = 0;
		if (av[pars.iac][0] == '-')
		{
			c = check_flag(av[pars.iac], &pars);
			if (c == 1)
				md5_hash("autre");
			if (c == 2)
				md5_hash("sur argu suivant");
			if (c == 3)
				md5_hash("stdin");
		}
		if (c == -1)
		{
			pars.iac++;
			pars.iarg = 1;
		}


	}
	return (1);
}