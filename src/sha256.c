/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sha256.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 17:30:12 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/07 17:30:12 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"



void        create_msa(t_sha_worker *worker)
{
    int     i;
    unsigned int s0;
    unsigned int s1;

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

void        slave_serves_worker(t_sha_worker *worker, t_sha_worker *slave)
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

void        make_sha_magic(t_sha_temp   *temp, t_sha_worker *slave,
        t_control *control, int i)
{
    temp->S1 = rightrotate(slave->E, 6) ^ rightrotate(slave->E, 11) ^
              rightrotate(slave->E, 25);
    temp->ch = (slave->E & slave->F) ^ ((~slave->E) & slave->G);
    temp->temp1 = temp->H + temp->S1 + temp->ch + control->sha_worker->K[i] +
                 control->sha_worker->w[i];
    temp->S0 = rightrotate(slave->A, 2) ^ rightrotate(slave->A, 13) ^
              lefttrotate(temp->A, 22);
    temp->maj = (slave->A & slave->B) ^ (slave->A & slave->C) ^
               (slave->B & slave->C);
    temp->temp2 = temp->S0 + temp->maj;
}
void        hash_256(t_control  *control)
{
    int     i;
    t_sha_temp   temp;
    t_sha_worker slave;

    i = 0;
    if (control->sha_worker == NULL)
    {
        if (!init_sha_worker(control))
            return ;
    }
    ft_bzero((void*)&temp, sizeof(t_sha_temp));
    ft_memcpy(&slave, control->sha_worker, sizeof(t_sha_worker));
    create_msa(worker);
    while (i < 63)
    {
        make_sha_magic(&temp, &slave, control, i);
        i++;
    }
    slave_serves_worker(control->sha_worker, &slave);
    ft_bzero((void*)&control->buf, sizeof(unsigned int) * 16);
}

int			sha256(t_control *control)
{
	if (control->type == FILE)
		control->file_only = 1;
	control->has_worked = 1;
	print_control(control);
	reset_control(control);
	return (1);
}