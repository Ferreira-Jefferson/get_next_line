/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_newline.test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:36:56 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/21 10:25:43 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "get_next_line_test.h"

MU_TEST(test_start_str)
{
	char	str[] = "\n123454321";
	
	int expected = 9;
	int result = ft_find_newline(str);
	
	mu_assert_int_eq(expected, result);
}

MU_TEST(test_end_str)
{
	char	str[] = "123454321\n";
	
	int expected = 0;
	int result = ft_find_newline(str);
	
	mu_assert_int_eq(expected, result);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_start_str);
	MU_RUN_TEST(test_end_str);
}

int	ft_find_newline_test(void)
{
	printf("%sft_find_newline: %s", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}