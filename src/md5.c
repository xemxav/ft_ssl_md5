/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   md5.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 09:48:46 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 09:48:46 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void			make_md5_magic(t_md5_worker *slave, unsigned int i)
{
	if (i < 16)
	{
		slave->F = (slave->B & slave->C) | ((~slave->B) & slave->D);
		slave->g = i;
	}
	if (i >= 16 && i < 32)
	{
		slave->F = (slave->D & slave->B) | ((~slave->D) & slave->C);
		slave->g = (5 * i + 1) % 16;
	}
	if (i >= 32 && i < 48)
	{
		slave->F = slave->B ^ slave->C ^ slave->D;
		slave->g = (3 * i + 5) % 16;
	}
	if (i >= 48 && i < 64)
	{
		slave->F = slave->C ^ (slave->B | (~slave->D));
		slave->g = (7 * i) % 16;
	}
}

static void			slave_serves_worker(t_md5_worker *worker,
		t_md5_worker *slave)
{
	worker->A += slave->A;
	worker->B += slave->B;
	worker->C += slave->C;
	worker->D += slave->D;
}

int					hash_md5_buf(t_control *control)
{
	unsigned int	i;
	t_md5_worker	slave;

	i = 0;
	if (!(control->md5_worker))
	{
		if (!init_md5_worker(control))
			return (FALSE);
	}
	ft_bzero(&slave, sizeof(t_sha_worker));
	ft_memcpy(&slave, control->md5_worker, sizeof(t_sha_worker));
	while (i < 64)
	{
		make_md5_magic(&slave, i);
		slave.F = slave.F + slave.A + g_k_md5[i] + control->buf[slave.g];
		slave.A = slave.D;
		slave.D = slave.C;
		slave.C = slave.B;
		slave.B = slave.B + lefttrotate(slave.F, g_s_md5[i]);
		i++;
	}
	slave_serves_worker(control->md5_worker, &slave);
	ft_bzero((void*)&control->buf, sizeof(unsigned int) * 16);
	return (TRUE);
}
