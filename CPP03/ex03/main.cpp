#include "DiamondTrap.hpp"

int main() {
    DiamondTrap a;
	DiamondTrap b ("Diamond");
    DiamondTrap c(b);
    DiamondTrap d;
    d = c; //so it should be b


    a.attack("Target A");
    b.attack("Target B");
	c.attack("Target B");
    a.takeDamage(5);
	a.beRepaired(4);
    // a.takeDamage(3);
	// a.takeDamage(5);
	// a.takeDamage(5);
	// b.takeDamage(9);
	// a.beRepaired(5);
	// b.beRepaired(5);
	// c.takeDamage(10);
	// c.beRepaired(3);
    for (int i = 0; i <= 51; ++i) {
        b.attack("Target C");
    }
    a.guardGate();
    b.guardGate();  // Should indicate that it is already guarding
	c.highFivesGuys();
	d.highFivesGuys();
	a.whoAmI();
	b.whoAmI();
	c.whoAmI();
	d.whoAmI();
    return 0;
}
