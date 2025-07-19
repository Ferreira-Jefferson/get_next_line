/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:55:54 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/19 18:17:07 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "get_next_line.h"

MU_TEST(initial_test) {
	char	*expected = "";
	char	*result = get_next_line(1);
	
	mu_assert_string_eq(expected, result);
}

MU_TEST(test_ft_strchr_grab_start_str) {
	char	str[] = "123454321";
	char	c = '1';

	char	*expected = "123454321";
	char	*result = ft_strchr(str, c);
	
	mu_assert_string_eq(expected, result);
}

MU_TEST(test_ft_strchr_grab_middle_str) {
	char	str[] = "123454321";
	char	c = '5';

	char	*expected = "54321";
	char	*result = ft_strchr(str, c);
	
	mu_assert_string_eq(expected, result);
}

MU_TEST(test_ft_strchr_grab_end_str) {
	char	str[] = "1234543210";
	char	c = '0';

	char	*expected = "0";
	char	*result = ft_strchr(str, c);
	
	mu_assert_string_eq(expected, result);
}

MU_TEST(test_ft_strchr_grab_null_terminator) {
	char	str[] = "1234543210";
	char	c = '\0';

	char	*expected = "";
	char	*result = ft_strchr(str, c);
	
	mu_assert_string_eq(expected, result);
}

MU_TEST(test_ft_strchr_not_value_in_str) {
	char	str[] = "1234543210";
	char	c = 'x';

	char	*expected = NULL;
	char	*result = ft_strchr(str, c);
	
	mu_assert_string_eq(expected, result);
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(initial_test);
	MU_RUN_TEST(test_ft_strchr_grab_start_str);
	MU_RUN_TEST(test_ft_strchr_grab_middle_str);
	MU_RUN_TEST(test_ft_strchr_grab_end_str);
	MU_RUN_TEST(test_ft_strchr_grab_null_terminator);
	MU_RUN_TEST(test_ft_strchr_not_value_in_str);
}

int	main(void)
{
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}