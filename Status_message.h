#pragma once
#include "base_message.h"
	class Status_message :public base_message
{
protected:
	short status;//(1 - 3)
public:
	void parseMessage();
	void parseBack();
	void print();
	Status_message(int messageId, int messageType, short status);
	Status_message();
	~Status_message();
};

