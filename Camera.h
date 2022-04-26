#pragma once
#include "base_message.h";
#include "Discover_message.h";
#include "Status_message.h";

#include "Buffer.h";
//#include "Simulator.h"
static int index=1;
class Camera
{
	
	int id;
	//Simulator s;
	base_message** message;
	Buffer*  bufferCamera;
	bool isActive;//isActive - האם המצלמה בפעילות
	void generate(int i);
	void sendToBuffer();
public:
	Status_message* createStatusMessage();
	Discover_message* createDiscoverMessage();
	void run();
	void stop();
	Camera();
	~Camera();

};