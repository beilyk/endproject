#pragma once
#include "base_message.h"
static int N = 5;
#include <mutex>
class Buffer
{
private:
	
	char** buffer;
	int index;
public:
	void addToBuffer(base_message** message);
	char** getBuffer();
	void cleanBuffer();
	Buffer();
	~Buffer();

};

