#include "Simulator.h"
#include<thread>
#include<iostream>
#include <chrono>

using namespace std::literals::chrono_literals;

void Simulator::run() {
	
	std::thread threadarr[6];
	std::cout << "simulator run";
	for (int i = 0; i < rc.get_num_camera(); i++) {
		threadarr[i] = std::thread(&Camera::run, camera_vec[i]);
	}
	   std::cout << "/n     press a char   /n";
	  

		   std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // sleep for 1 second
	   std::cout << "camera_vec" << camera_vec[0].get_bufferCamera().getBuffer();
	   char x=getchar();
	  
	   
		for (int i = rc.get_num_camera(); i < (rc.get_num_camera())*2; i++) {
			threadarr[i] = std::thread(&Camera::stop, camera_vec[i]);
		}
		for (int i = 0; i < rc.get_num_camera(); i++) {
			threadarr[i].join();

		}
	
}


Simulator::Simulator() {
	 rc = read_config();
	
	for (int i = 0; i <rc.get_num_camera(); i++) {
		std::cout <<i<< "camera_vec\n";
		camera_vec[i] = Camera();
	}
	}
	


