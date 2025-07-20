/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 07:02:18 by jtertuli          #+#    #+#             */
/*   Updated: 2025/07/20 13:11:39 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_next_line_test(void);
int	ft_strchr_test(void);
int ft_strdup_test(void);
int	ft_strlen_test(void);

int	main(void)
{
	int result_all_test = (ft_strchr_test() == ft_strdup_test()) == \
	(get_next_line_test() == ft_strlen_test());
		
	return (result_all_test);
}