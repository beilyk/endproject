
#include<iostream>

#include "Simulator.h"


void main() {
	Simulator s = Simulator::Simulator();
	s.run();
	getchar();
	/*Camera*c = new Camera();
	(*c).run();*/
	/*std::thread t1((*c).run());
	std::this_thread::sleep_for(15s);
	std::thread t2(c.stop());
	(*c).run();*/



}