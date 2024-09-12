#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("adad");
		HumanA bob("bebebe", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("ggg");
		jim.attack();
	}
	return 0;
}