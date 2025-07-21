/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 06:36:56 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/21 10:25:39 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "get_next_line_test.h"

MU_TEST(test_null_str)
{
	char	*str = NULL;

	char	*expected = NULL;
	char	*result = ft_strdup(str);
	
	mu_assert_string_eq(expected, result);
}

MU_TEST(test_empty_str)
{
	char	str[] = "";

	char	expected[] = "";
	char	*result = ft_strdup(str);
	
	mu_assert_string_eq(expected, result);
	free(result);
}
MU_TEST(test_valid_str)
{
	char	str[] = "12345";

	char	expected[] = "12345";
	char	*result = ft_strdup(str);
	
	mu_assert_string_eq(expected, result);
	free(result);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_null_str);
	MU_RUN_TEST(test_empty_str);
	MU_RUN_TEST(test_valid_str);
}

int ft_strdup_test(void)
{
	printf("%sft_strdup_test: %s", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}