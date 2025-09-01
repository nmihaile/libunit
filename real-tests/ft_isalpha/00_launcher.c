/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:45:12 by nweber            #+#    #+#             */
/*   Updated: 2025/09/01 09:22:44 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../framework/inc/libunit.h"
#include "../../libft/libft.h"
#include "../test_functions.h"

// This right here, is our test routine
int	ft_isalpha_launcher(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic_Test", &ft_isalpha_basic_test);
	load_test(&testlist, "Digit_Test", &ft_isalpha_digit_test);
	load_test(&testlist, "Whitespace_Test", &ft_isalpha_whitespace_test);
	load_test(&testlist, "Zero_Test", ft_islpha_zero_test);
	load_test(&testlist, "Underscore_Test", &ft_isalpha_underscore_test);
	load_test(&testlist, "Punctuation_Test", &ft_isalpha_punctuation_test);
	load_test(&testlist, "Extended_Ascii_Test", \
		&ft_isalpha_extended_ascii_test);
	load_test(&testlist, "Negative_Test", &ft_isalpha_negative_test);
	load_test(&testlist, "Int_Min_Test", &ft_isalpha_int_min_test);
	load_test(&testlist, "Int_Max_Test", &ft_isalpha_int_max_test);
	return (launch_tests("ft_isalpha", testlist));
}
