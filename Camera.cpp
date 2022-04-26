#include "Camera.h"
#include "Buffer.h"
#include <random>
#include <iostream>

void Camera::generate(int i) {
	base_message* mess;
	//Simulator s;
	int num = rand() % 2 + 1;
	if (num == 1) {
		mess = createDiscoverMessage();
	}
	else{
		mess = createStatusMessage();
	}

	    message = (base_message**)realloc(message, sizeof(base_message*)*5);
		*(message+i) = mess;
		//cheek +i
		
}
void  Camera::sendToBuffer() {
	if (message) {
		bufferCamera->addToBuffer(*message);
		/*for (int i = 0; i < 5; i++) {
			free (message [i]);
		}*/
		free(message);
	}
	
}
void Camera::run() {
	std::cout << "camera run";
	while (isActive) {
		std::cout << "camera is active";
		for (int i = 0; i <= 5 && isActive; i++) {
			generate(i);
		}
		sendToBuffer();
	}
}
void Camera::stop() {
	isActive = false;
}
Discover_message* Camera::createDiscoverMessage()
{
	static int id = 100;
	id++;
	Discover_message* dm = new Discover_message(id, 2, rand() % 9500 + 500, rand() % 361, rand() % 1001);
	return dm;
}
Status_message* Camera::createStatusMessage()
{
	static int id = 1;
	id++;
	Status_message* sm = new Status_message(id, 1, rand() % 3 + 1);
	return sm;
}
Camera::Camera() {
	std :: cout<<"camera";
	std::cout << "index  "<< index;
	
	id = index++;
	std::cout << id;
	isActive = true;
	bufferCamera= new Buffer();
	message = (base_message**)malloc( sizeof(base_message*));
}
Camera::~Camera() {
	/*free(bufferCamera);*/
}