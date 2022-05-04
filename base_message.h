#pragma once
#include <iostream>
class base_message
{
protected:
	unsigned char* messageBuffer;
	int messageId;
	int messageType;
public:
	base_message(int messageId, int messageType);
	virtual void parseMessage() = 0;
	virtual void parseBack() = 0;
	virtual void print() = 0;
	unsigned char* getMessageBuffer();
};

