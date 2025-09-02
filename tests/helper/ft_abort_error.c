/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abort_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:43:12 by nweber            #+#    #+#             */
/*   Updated: 2025/09/02 11:46:06 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Remove all CFLAGS so that this demonstration function compiles on linux.
int	ft_abort_error(void)
{
	char	*p;

	p = malloc(1);
	if (!p)
		return (-1);
	free(p);
	free(p);
	return (0);
}
