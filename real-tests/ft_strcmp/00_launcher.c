/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:53:34 by nweber            #+#    #+#             */
/*   Updated: 2025/09/01 09:22:57 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../framework/inc/libunit.h"
#include "../../libft/libft.h"
#include "../test_functions.h"

int	ft_strcmp_launcher(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "Equal_Test", &ft_strcmp_equal_test);
	load_test(&testlist, "Less_Test", &ft_strcmp_less_test);
	load_test(&testlist, "Greater_Test", &ft_strcmp_greater_test);
	load_test(&testlist, "Empty_NonEmpty_Test", \
		&ft_strcmp_empty_non_nonempty_test);
	load_test(&testlist, "Both_Empty_Test", \
		&ft_strcmp_both_empty_test);
	load_test(&testlist, "Prefix_Less_Test", &ft_strcmp_prefix_less_test);
	load_test(&testlist, "Diff_At_End_Test", &ft_strcmp_diff_at_end_test);
	load_test(&testlist, "Case_Sensitive_Test", \
		&ft_strcmp_case_sensitive_test);
	load_test(&testlist, "Extended_Ascii_Order_Test", \
		&ft_strcmp_extended_ascii_order_test);
	return (launch_tests("ft_strcmp", testlist));
}
