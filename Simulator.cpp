#include "Simulator.h"
#include<thread>
#include<iostream>
using namespace std::literals::chrono_literals;

void Simulator::run() {
	char c;
	std::cout << "simulator run";
	for (int i = 0; i < 3; i++) {
		std::thread threadrun(&Camera::run, camera_vec);
	}
	c = getchar();
	while (c == NULL) {
		c = getchar();
	}

		for (int i = 0; i < 3; i++) {
			std::thread threadstop(&Camera::stop, camera_vec);
		}
	
}


Simulator::Simulator() {
	//camera_vec = (Camera**)(malloc(sizeof(Camera*)*3));
	for (int i = 0; i < 3; i++) {
		camera_vec[i] = Camera::Camera();
		//camera_vec[i] = new Camera();//Camera::Camera();
	}
	}
	


