#pragma once
#include "base_message.cpp";
#include "Buffer.h";
#include "Simulator.h"
class Camera
{
	char id;
	Simulator s;
	base_message** message;
	Buffer*  bufferCamera;
	bool isActive;//isActive - האם המצלמה בפעילות
	void generate(int i);
	void sendToBuffer();
public:
	void run();
	void stop();
	Camera();
	~Camera();

};