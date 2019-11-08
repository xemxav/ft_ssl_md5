/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sha256.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 09:33:10 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 09:33:10 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void			create_msa(t_h_worker *worker)
{
	int				i;
	unsigned int	s0;
	unsigned int	s1;

	i = 16;
	while (i < 64)
	{
		s0 = rightrotate(worker->w_sha[i - 15], 7) ^
				rightrotate(worker->w_sha[i - 15], 18)
				^ (worker->w_sha[i - 15] >> 3);
		s1 = rightrotate(worker->w_sha[i - 2], 17) ^
				rightrotate(worker->w_sha[i - 2], 19)
				^ (worker->w_sha[i - 2] >> 10);
		worker->w_sha[i] = worker->w_sha[i - 16] + s0 + worker->w_sha[i - 7] + s1;
		i++;
	}
}

void				slave_serves_worker(t_h_worker *worker, t_h_worker *slave,
		int max_reg_ind)
{
	int				i;

	i = 0;
	while (i < max_reg_ind)
	{
		worker->reg[i] += slave->reg[i];
		i++;
	}
}

static void			make_sha_magic(t_sha_temp *temp, t_h_worker *slave, int i)
{
	temp->S1 = rightrotate(slave->reg[REG_E], 6) ^
			rightrotate(slave->reg[REG_E], 11) ^
			rightrotate(slave->reg[REG_E], 25);
	temp->ch = (slave->reg[REG_E] & slave->reg[REG_F]) ^ ((~(slave->reg[REG_E]))
			& slave->reg[REG_G]);
	temp->temp1 = slave->reg[REG_H] + temp->S1 + temp->ch + g_k_sha[i] +
			slave->w_sha[i];
	temp->S0 = rightrotate(slave->reg[REG_A], 2) ^ rightrotate(slave->reg[REG_A], 13)
			^ rightrotate(slave->reg[REG_A], 22);
	temp->maj = (slave->reg[REG_A] & slave->reg[REG_B]) ^ (slave->reg[REG_A]
			&slave->reg[REG_C]) ^ (slave->reg[REG_B] & slave->reg[REG_C]);
	temp->temp2 = temp->S0 + temp->maj;
}

static void			add_temp_to_slave(t_sha_temp *temp, t_h_worker *slave)
{
	slave->reg[REG_H] = slave->reg[REG_G];
	slave->reg[REG_G] = slave->reg[REG_F];
	slave->reg[REG_F] = slave->reg[REG_E];
	slave->reg[REG_E] = slave->reg[REG_D] + temp->temp1;
	slave->reg[REG_D] = slave->reg[REG_C];
	slave->reg[REG_C] = slave->reg[REG_B];
	slave->reg[REG_B] = slave->reg[REG_A];
	slave->reg[REG_A] = temp->temp1 + temp->temp2;
}

int					hash_sha256_buf(t_control *control)
{
	int				i;
	t_sha_temp		temp;
	t_h_worker		slave;

	i = 0;
	if (control->worker == NULL)
	{
		if (init_sha_worker(control) == ERROR)
			return (ERROR);
	}
	ft_bzero((void*)&temp, sizeof(t_sha_temp));
	ft_memcpy(&slave, control->worker, sizeof(t_h_worker));
	init_w(&slave, control->buf);
	create_msa(&slave);
	while (i < 64)
	{
		make_sha_magic(&temp, &slave, i);
		add_temp_to_slave(&temp, &slave);
		i++;
	}
	slave_serves_worker(control->worker, &slave, control->reg_nb - 1);
	ft_bzero((void*)&control->buf, sizeof(unsigned int) * 16);
	return (TRUE);
}
