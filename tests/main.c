/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:58:49 by nweber            #+#    #+#             */
/*   Updated: 2025/09/01 09:22:00 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/inc/libunit.h"
#include "dummy.h"

int	main(void)
{
	static char	header[] = \
		LIGHTCYAN""BOLD"---------«««<< DUMMY TESTING >>»»»---------\n\n"RESET;

	ft_putstr_fd(header, 1);
	ft_dummy_launcher();
	ftu_print_final_result();
	return (0);
}
