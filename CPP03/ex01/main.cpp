#include "ScavTrap.hpp"

int main() {
    ScavTrap a;
	ScavTrap b("Scavvy");
    ScavTrap c(b);
    ScavTrap d;
    d = c; //so it should be b


    a.attack("Target A");
    b.attack("Target B");
	c.attack("Target B");
    a.takeDamage(5);
	a.beRepaired(5);
    // a.takeDamage(3);
	// a.takeDamage(5);
	// a.takeDamage(5);
	// b.takeDamage(9);
	// a.beRepaired(5);
	// b.beRepaired(5);
	// c.takeDamage(10);
	// c.beRepaired(3);
    for (int i = 0; i <= 51; ++i) {
        c.attack("Target C");
    }
    d.guardGate();
    a.guardGate();
    b.guardGate();
    c.guardGate();
    return 0;
}
