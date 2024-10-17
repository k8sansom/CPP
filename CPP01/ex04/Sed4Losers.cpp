#include "Sed4Losers.hpp"

Sed4Losers::Sed4Losers( std::string filename, std::string s1, std::string s2) : _filename(filename), _s1(s1), _s2(s2) {
}

Sed4Losers:: ~Sed4Losers() {}

int	Sed4Losers::replace(void) {
	std::ifstream	infile(this->_filename.c_str());
	std::ofstream	outfile((this->_filename + ".replace").c_str());
	std::string 	line = "";
	if (!infile) {
		std::cout << "Error opening file: " << this->_filename << std::endl;
		return 1;
	}
	if (!outfile) {
		infile.close();
		std::cout << "Error creating " << this->_filename << ".replace" << std::endl;
		return 1;
	}
    while (std::getline(infile, line)) {
        size_t pos = 0;
        while ((pos = line.find(this->_s1, pos)) != std::string::npos) {
            outfile << line.substr(0, pos) << this->_s2;
            pos += this->_s1.length();
            line = line.substr(pos);
            pos = 0;
        }
        outfile << line << std::endl;
    }
	infile.close();
	outfile.close();
	return 0;
}