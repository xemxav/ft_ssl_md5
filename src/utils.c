/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xmoreau <xmoreau@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 19:03:23 by xmoreau      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 19:03:23 by xmoreau     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

unsigned int    rightrotate(unsigned int n, unsigned int d)
{
    return ((n >> d) | (n << (32 - d)));
}

unsigned int    lefttrotate(unsigned int n, unsigned int d)
{
    return ((n << d) | (n >> (32 - d)));
}
