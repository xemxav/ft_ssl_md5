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

static void			make_md5_magic(t_h_worker *slave, unsigned int i)
{
	if (i < 16)
	{
		slave->f_md5 = (slave->reg[REG_B] & slave->reg[REG_C]) |
				((~slave->reg[REG_B]) & slave->reg[REG_D]);
		slave->index_md5 = i;
	}
	if (i >= 16 && i < 32)
	{
		slave->f_md5 = (slave->reg[REG_D] & slave->reg[REG_B]) |
				((~slave->reg[REG_D]) & slave->reg[REG_C]);
		slave->index_md5 = (5 * i + 1) % 16;
	}
	if (i >= 32 && i < 48)
	{
		slave->f_md5 = slave->reg[REG_B] ^ slave->reg[REG_C] ^
				slave->reg[REG_D];
		slave->index_md5 = (3 * i + 5) % 16;
	}
	if (i >= 48 && i < 64)
	{
		slave->f_md5 = slave->reg[REG_C] ^ (slave->reg[REG_B] |
				(~slave->reg[REG_D]));
		slave->index_md5 = (7 * i) % 16;
	}
}

int					hash_md5_buf(t_control *control)
{
	unsigned int	i;
	t_h_worker		slave;

	i = 0;
	if (!(control->worker))
	{
		if (!init_md5_worker(control))
			return (ERROR);
	}
	ft_bzero(&slave, sizeof(t_h_worker));
	ft_memcpy(&slave, control->worker, sizeof(t_h_worker));
	while (i < 64)
	{
		make_md5_magic(&slave, i);
		slave.f_md5 = slave.f_md5 + slave.reg[REG_A] + g_k_md5[i] +
				control->buf[slave.index_md5];
		slave.reg[REG_A] = slave.reg[REG_D];
		slave.reg[REG_D] = slave.reg[REG_C];
		slave.reg[REG_C] = slave.reg[REG_B];
		slave.reg[REG_B] = slave.reg[REG_B] + lefttrotate(slave.f_md5, g_s_md5[i]);
		i++;
	}
	slave_serves_worker(control->worker, &slave, control->reg_nb - 1);
	ft_bzero((void*)&control->buf, sizeof(unsigned int) * 16);
	return (TRUE);
}
