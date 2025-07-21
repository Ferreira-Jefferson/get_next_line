/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:55:54 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/21 10:25:25 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "get_next_line_test.h"

char	*create_file_test(char *text)
{
	char *path = "test_str_output.txt";
	int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    write(fd, text, ft_strlen(text));
    close(fd);
	return (path);
}

void	close_file_test(int fd, char *path)
{
	close(fd);
    unlink(path);
}

MU_TEST(initial_test)
{
		
	char	*path = create_file_test("");
	int		fd = open(path, O_RDONLY);
	
	char	*expected = "";
	char	*result = get_next_line(fd);

	mu_assert_string_eq(expected, result);
	
    close_file_test(fd, path);
}
int fd;
char	*path;
MU_TEST(test_return_firt_occurrence_of_newline)
{
	char	text[] = "0123\nabcdefgh\n\n0\n";

	char	*path = create_file_test(text);
	fd = open(path, O_RDONLY);

	char	*expected = "0123\n";
	char	*result = get_next_line(fd);
    mu_assert_string_eq(result, expected);

}

MU_TEST(test_return_second_occurrence_of_newline)
{
	char	*expected = "abcdefgh\n";
	char	*result = get_next_line(fd);
    mu_assert_string_eq(result, expected);
}

MU_TEST(test_return_third_occurrence_of_newline)
{
	char	*expected = "\n";
	char	*result = get_next_line(fd);
    mu_assert_string_eq(result, expected);
	
    close_file_test(fd, path);
}

MU_TEST_SUITE(test_suite)
{
	MU_RUN_TEST(initial_test);
	MU_RUN_TEST(test_return_firt_occurrence_of_newline);
	MU_RUN_TEST(test_return_second_occurrence_of_newline);
	MU_RUN_TEST(test_return_third_occurrence_of_newline);
}

int	get_next_line_test(void)
{
	printf("%sget_next_line_test: %s", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}