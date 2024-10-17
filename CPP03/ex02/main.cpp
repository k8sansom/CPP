#include "FragTrap.hpp"

int main() {
    FragTrap a;
	FragTrap b("Fraggy");
    FragTrap c(b); // should be b
    FragTrap d;
    d = c; //should also be b


    a.attack("Target A");
    b.attack("Target B");
	c.attack("Target B");
    a.takeDamage(5);
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
    // for (int i = 0; i < 101; ++i) {
    //     c.attack("Target C");
    // }
    a.highFivesGuys();
    b.highFivesGuys();
	c.highFivesGuys();
	d.highFivesGuys();
    return 0;
}
