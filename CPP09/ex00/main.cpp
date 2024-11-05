#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange exchange;
		exchange.process(av[1]);
	} catch (std::exception const &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}