#include "Camera.h"
#include "Buffer.h"
#include <random>
void Camera::generate(int i) {
	base_message* mess;
	int num = rand() % 2 + 1;
	if (num == 1)
		mess = s.createDiscoverMessage();
	else
		mess = s.createStatusMessage();
	    message = (base_message**)realloc(message, sizeof(base_message*));
		message[i] = mess;
		//cheek +i
		
}
void  Camera::sendToBuffer() {
	if (message) {
		bufferCamera->addToBuffer(*message);
		for (int i = 0; i < 5; i++) {
			free (message [i]);
		}
		free(message);
	}
	
}
void Camera::run() {
	while (isActive) {
		
		for (int i = 0; i <= 5 && isActive; i++) {
			generate(i);
		}
		sendToBuffer();
	}
}
void Camera::stop() {
	isActive = false;
}
Camera::Camera() {
	isActive = true;
	bufferCamera= new Buffer();
	
}
Camera::~Camera() {
	free(bufferCamera);
}