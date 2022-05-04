#include "Camera.h"
#include <random>


void Camera::generate(int i) {
	base_message* mess;
	
	int num = rand() % 2 + 1;
	if (num == 1) {
		mess = createDiscoverMessage();
	}
	else{
		mess = createStatusMessage();
	}

	    message = (base_message**)realloc(message, sizeof(base_message*)*5);
		*(message+i) = mess;
		
		
}
void  Camera::sendToBuffer() {
	
	if (message) {
		bufferCamera->addToBuffer(message);
		for (int i = 0; i < N; i++) {

			free(message[i]->getMessageBuffer());
		
			delete(message[i]);
			
		}

		std::cout << message;
		message = nullptr;
	}
	
}
void Camera::run() {
	
	while (isActive) {
		for (int i = 0; i <=N && isActive; i++) {
			generate(i);
		}
		sendToBuffer();
	}
}
//
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
Buffer Camera::get_bufferCamera() {
	return *bufferCamera;
}
Camera::Camera() {
	id = index++;
	isActive = true;
	bufferCamera = new Buffer();
	message = (base_message**)malloc( sizeof(base_message*));

}

Camera::~Camera() {
	
}