/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_stdout_success_test.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:21:05 by nmihaile          #+#    #+#             */
/*   Updated: 2025/09/02 11:46:34 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../demo.h"
#include "../../framework/inc/libunit.h"

int	ft_stdout_success_test(void)
{
	if (compare_stdout(ft_stdout_helper, "Hello unit_test.") == 0)
		return (0);
	else
		return (-1);
}
