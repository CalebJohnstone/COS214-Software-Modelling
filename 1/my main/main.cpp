#include "Lion.h"
#include "Cheetah.h"
#include "Wolf.h"
#include "WildDog.h"

int main() {
	//prey
	Prey* springbok = new Prey(80, "springbok", 5);
	Prey* turtle = new Prey(30, "turtle", 3);
	Prey* rabbit = new Prey(50, "rabbit", 10);

	//predators
	Predator* lion = new Lion(100, "surround", 20, "snipe");
	Predator* cheetah = new Cheetah(120, "chase", 25, "climb");
	Predator* wolf = new Wolf(140, "grab", 30, "side step");
	Predator* wildDog = new WildDog(135, "scavenge", 22, "snap");

	//clone the springbok
	Prey* s = springbok->clone();
	cout << "s" << endl;
	cout << "type: " << s->getType() << endl;

	//hunting
	lion->hunt(springbok);
	cout << endl;

	cheetah->hunt(turtle);
	cout << endl;

	wolf->hunt(rabbit);
	cout << endl;

	//de-allocate the objects
	delete springbok;
	delete turtle;
	delete rabbit;

	delete lion;
	delete cheetah;
	delete wolf;
	delete wildDog;

	return 0;
}