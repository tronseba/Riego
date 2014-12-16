// Do not remove the include below
#include "Riego.h"
#include "Menu.h"
#include "Trigger.h"
#include <Time.h>

Menu menu = Menu();

Trigger* triggers[] = {new Trigger(),new Trigger(),new Trigger(),new Trigger()};




//The setup function is called once at startup of the sketch
void setup() {
	setTime(00, 00, 00, 28, 11, 2014);

}

// The loop function is called in an endless loop
void loop() {
	menu.processKeys();

	menu.drawMenu();
}
