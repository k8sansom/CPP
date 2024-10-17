#include "Sed4Losers.hpp"

int	main(int ac, char **av) {
	if (ac != 4) {
		std::cout << 
		"Usage: a filename and two strings, s1 to be found, and s2 to replace it."
		<< std::endl;
		return 1;
	}
	else {
		Sed4Losers Sed4Losers(av[1], av[2], av[3]);
		if (Sed4Losers.replace() != 0)
			return 1;
	}
	return 0;
}