/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:55:54 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/19 17:02:34 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "get_next_line.h"

MU_TEST(initial_test) {
	char	*expected = "";
	char	*result = get_next_line(1);
	
	mu_assert_string_eq(expected, result);
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(initial_test);
}

int	main(void)
{
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}