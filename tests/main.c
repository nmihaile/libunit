/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:58:49 by nweber            #+#    #+#             */
/*   Updated: 2025/09/02 11:48:51 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../framework/inc/libunit.h"
#include "demo.h"

int	main(void)
{
	static char	header[] = \
		LIGHTCYAN""BOLD"---------«««<< DUMMY TESTING >>»»»---------\n\n"RESET;

	ft_putstr_fd(header, 1);
	ft_demo_launcher();
	ftu_print_final_result();
	return (0);
}
