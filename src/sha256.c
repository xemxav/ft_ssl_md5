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

unsigned int    rightrotate(unsigned int n, unsigned int d)
{
    return ((n >> d) | (n << (32 - d)));
}

void        create_msa(t_sha_worker *worker)
{
    int     i;

    i = 16;
    while (i < 64)
    {
        worker-s0 = rightrotate(worker->w[i - 15], 7) ^
                rightrotate(worker->w[i - 15], 18)
                ^ (worker->w[i - 15] >> 3);
        worker-s0 = rightrotate(worker->w[i - 2], 17) ^
                rightrotate(worker->w[i - 2], 19)
             ^ (worker->w[i - 2] >> 10);
        worker->w[i] = worker->w[i - 16] + worker-s0 + worker->w[i - 7] + s1;
        i++;
    }
}

void        hash_256(t_control  *control)
{
    t_sha_worker *worker;

    worker = control->sha_worker;

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