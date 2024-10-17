/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:15:17 by ksansom           #+#    #+#             */
/*   Updated: 2024/03/22 09:42:47 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int	j;
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; av[i]; i++)
	{
		j = -1;
		while (av[i][++j]) {
			if (j == 0 && std::isspace(av[i][j]))
				++j;
			if (std::isspace(av[i][j]) && av[i][j + 1] == '\0')
			 	break ;
			std::cout << (char)std::toupper(av[i][j]);
		}
		if (i < ac - 1)
			std::cout << ' ';
	}
	std::cout << std::endl;
	return (0);
}