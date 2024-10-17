#include "ClapTrap.hpp"

int main() {
    // Creating ClapTrap instances
    ClapTrap a;
    ClapTrap b("Clappy");
	ClapTrap c("Showoff");
	c = b;

    a.attack("Target A");
    b.attack("Target B");
	c.attack("Target B");

    a.takeDamage(5);
	a.beRepaired(5);
    a.takeDamage(3);
	a.takeDamage(5);
	a.takeDamage(5);
	b.takeDamage(9);
	a.beRepaired(5);
	b.beRepaired(5);
	c.takeDamage(10);
	c.beRepaired(3);

    for (int i = 0; i < 10; ++i) {
        b.attack("Target C");
    }
    return 0;
}
