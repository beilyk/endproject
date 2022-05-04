#pragma once
//#include "base_message.h";
#include "Discover_message.h";
#include "Status_message.h";
#include "Buffer.h";
//#include "Simulator.h"
 
static int index=1;
class Camera
{
	
	int id;
	base_message** message=nullptr;
	Buffer  *bufferCamera;
	bool isActive;
	void generate(int i);
	void sendToBuffer();
public:
	Buffer get_bufferCamera();
	Status_message* createStatusMessage();
	Discover_message* createDiscoverMessage();
	void run();
	void stop();
	Camera();
	~Camera();

};