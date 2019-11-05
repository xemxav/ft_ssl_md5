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

static void			create_msa(t_sha_worker *worker)
{
	int				i;
	unsigned int	s0;
	unsigned int	s1;

	i = 16;
	while (i < 64)
	{
		s0 = rightrotate(worker->w[i - 15], 7) ^
				rightrotate(worker->w[i - 15], 18)
				^ (worker->w[i - 15] >> 3);
		s1 = rightrotate(worker->w[i - 2], 17) ^
				rightrotate(worker->w[i - 2], 19)
				^ (worker->w[i - 2] >> 10);
		worker->w[i] = worker->w[i - 16] + s0 + worker->w[i - 7] + s1;
		i++;
	}
}

static void			slave_serves_worker(t_sha_worker *worker,
		t_sha_worker *slave)
{
	worker->A += slave->A;
	worker->B += slave->B;
	worker->C += slave->C;
	worker->D += slave->D;
	worker->E += slave->E;
	worker->F += slave->F;
	worker->G += slave->G;
	worker->H += slave->H;
}

static void			make_sha_magic(t_sha_temp *temp, t_sha_worker *slave, int i)
{
	temp->S1 = rightrotate(slave->E, 6) ^ rightrotate(slave->E, 11) ^
			rightrotate(slave->E, 25);
	temp->ch = (slave->E & slave->F) ^ ((~(slave->E)) & slave->G);
	temp->temp1 = slave->H + temp->S1 + temp->ch + g_k_sha[i] +
			slave->w[i];
	temp->S0 = rightrotate(slave->A, 2) ^ rightrotate(slave->A, 13) ^
			rightrotate(slave->A, 22);
	temp->maj = (slave->A & slave->B) ^ (slave->A & slave->C) ^
			(slave->B & slave->C);
	temp->temp2 = temp->S0 + temp->maj;
}

static void			add_temp_to_slave(t_sha_temp *temp, t_sha_worker *slave)
{
	slave->H = slave->G;
	slave->G = slave->F;
	slave->F = slave->E;
	slave->E = slave->D + temp->temp1;
	slave->D = slave->C;
	slave->C = slave->B;
	slave->B = slave->A;
	slave->A = temp->temp1 + temp->temp2;
}

int					hash_sha256_buf(t_control *control)
{
	int				i;
	t_sha_temp		temp;
	t_sha_worker	slave;

	i = 0;
	if (control->sha_worker == NULL)
	{
		if (!init_sha_worker(control))
			return (FALSE);
	}
	ft_bzero((void*)&temp, sizeof(t_sha_temp));
	ft_memcpy(&slave, control->sha_worker, sizeof(t_sha_worker));
	init_w(&slave, control->buf);
	create_msa(&slave);
	while (i < 64)
	{
		make_sha_magic(&temp, &slave, i);
		add_temp_to_slave(&temp, &slave);
		i++;
	}
	slave_serves_worker(control->sha_worker, &slave);
	ft_bzero((void*)&control->buf, sizeof(unsigned int) * 16);
	return (TRUE);
}
