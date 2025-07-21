/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 07:59:37 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/21 10:25:34 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "get_next_line_test.h"

MU_TEST(test_empty_str)
{
	char str[] = "";
	
	size_t expected = 0;
	size_t result = ft_strlen(str);

	mu_assert_int_eq(expected, result);
}

MU_TEST(test_str_whith_5_char_should_return_5)
{
	char str[] = "12345";
	
	size_t expected = 5;
	size_t result = ft_strlen(str);

	mu_assert_int_eq(expected, result);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(test_empty_str);
	MU_RUN_TEST(test_str_whith_5_char_should_return_5);
}
int	ft_strlen_test(void)
{
	printf("ft_strlen_test: ");
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);	
}