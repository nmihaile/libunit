/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:58:34 by nweber            #+#    #+#             */
/*   Updated: 2025/09/02 10:49:01 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../framework/inc/libunit.h"
#include "../dummy.h"

int	ft_dummy_launcher(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "OK_Test", &ft_ok_test);
	load_test(&testlist, "KO_Test", &ft_ko_test);
	load_test(&testlist, "SEGV_Test", &ft_segv_test);
	load_test(&testlist, "BUSE_Test", &ft_bus_error_test);
	load_test(&testlist, "ABORT_Test", &ft_abort_test);
	load_test(&testlist, "SFPE_Test", &ft_sigfpe_test);
	load_test(&testlist, "PIPE_Test", &ft_pipe_test);
	load_test(&testlist, "SIGILL_Test", &ft_sigill_test);
	load_test(&testlist, "TIMEOUT_Test", &ft_timeout_test);
	load_test(&testlist, "STDOUT_SUCCESS_Test", &ft_stdout_success_test);
	load_test(&testlist, "STDOUT_ERROR_Test", &ft_stdout_error_test);
	return (launch_tests("Dummy_Test", testlist));
}
