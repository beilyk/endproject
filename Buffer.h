#pragma once
#include "base_message.h"

class Buffer
{
private:
	char** buffer;
	int index;
public:
	void addToBuffer(base_message* message);
	char** getBuffer();
	void cleanBuffer();
	 Buffer();
	 ~Buffer();

};

