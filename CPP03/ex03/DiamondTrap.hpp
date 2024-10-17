# ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    public:
        DiamondTrap();
        DiamondTrap(const std::string name);
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap &operator=(const DiamondTrap &src);
        virtual ~DiamondTrap();

        void attack(const std::string &target);
        void whoAmI();

    private:
        std::string _name;
};

#endif