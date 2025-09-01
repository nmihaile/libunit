/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:32:31 by nmihaile          #+#    #+#             */
/*   Updated: 2025/09/01 09:23:01 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../framework/inc/libunit.h"
#include "../../libft/libft.h"
#include "../test_functions.h"

// This right here, is our test routine
int	ft_strlen_launcher(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic_Test", &ft_strlen_basic_test);
	load_test(&testlist, "NULL_Test", &ft_strlen_null_test);
	load_test(&testlist, "Empty_Test", &ft_strlen_empty_test);
	load_test(&testlist, "Whitespace_Test", &ft_strlen_whitespace_test);
	load_test(&testlist, "42Chars_Test", &ft_strlen_42chars_test);
	return (launch_tests("ft_strlen", testlist));
}
