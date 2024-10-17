#include "Harl.hpp"

int	main(int ac, char **av) {
	Harl	Harl;
	if (ac != 2) {
		std::cout << "USAGE: ./harlFilter <complaint level>" << std::endl;
		return 1;
	}
	Harl.complain(av[1]);
	return 0;
}