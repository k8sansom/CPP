#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	*this = copy;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src) {
	(void) src;
	return *this;
}
ScalarConverter::~ScalarConverter(){}

void	ScalarConverter::convert(const std::string& literal) {
    double toDouble = 0.0; 
    bool 	isSpecial = false;

	if (literal == "-inff" || literal == "-inf") {
		toDouble = -std::numeric_limits<double>::infinity();
		isSpecial = true;
	} else if (literal == "+inff" || literal == "+inf") {
		toDouble = std::numeric_limits<double>::infinity();
		isSpecial = true;
	} else if (literal == "nanf" || literal == "nan") {
		toDouble = std::numeric_limits<double>::quiet_NaN();
		isSpecial = true;
	}

    if (!isSpecial) {
		if (literal.length() == 1 && isalpha(literal[0])) {
            toDouble = static_cast<double>(literal[0]);
        } else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
			toDouble = static_cast<double>(literal[1]);
        } else {
			std::string literalWithoutF = literal;
            if (literal.back() == 'f') {
                literalWithoutF = literal.substr(0, literal.size() - 1);
            }
            std::istringstream ss(literalWithoutF);
			ss >> toDouble;
			if (ss.fail() || !ss.eof()) {
				std::cerr << "Invalid input literal" << std::endl;
				return ;
			}
		}
    }

	if (isSpecial) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(toDouble) << "f" << std::endl;
		std::cout << "double: " << toDouble << std::endl;
		return ;
	}
    if (toDouble >= 0 && toDouble <= 127 && std::isprint(static_cast<int>(toDouble))) {
        std::cout << "char: '" << static_cast<char>(toDouble) << "'" << std::endl;
    } else if (toDouble >= 0 && toDouble <= 127) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }
    if (toDouble >= std::numeric_limits<int>::min() && toDouble <= std::numeric_limits<int>::max()) {
        std::cout << "int: " << static_cast<int>(toDouble) << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }
    std::cout << "float: " << static_cast<float>(toDouble);
    if (static_cast<float>(toDouble) == static_cast<int>(toDouble)) {
        std::cout << ".0";
    }
    std::cout << "f" << std::endl;
    std::cout << "double: " << toDouble;
    if (toDouble == static_cast<int>(toDouble)) {
        std::cout << ".0";
    }
    std::cout << std::endl;
}
