# ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    public:
        Brain();
        ~Brain();
        Brain(const Brain& copy);
        Brain& operator=(const Brain& src);
		
		void setIdea(int index, const std::string& idea);
    	std::string getIdea(int index) const;
    private:
        std::string _ideas[100];
};
#endif