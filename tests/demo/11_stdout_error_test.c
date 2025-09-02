/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_stdout_error_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:46:14 by nmihaile          #+#    #+#             */
/*   Updated: 2025/09/02 10:49:49 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../dummy.h"
#include "../../framework/inc/libunit.h"

int	ft_stdout_error_test(void)
{
	if (compare_stdout(ft_stdout_helper, "Hello 42") == 0)
		return (0);
	else
		return (-1);
}
