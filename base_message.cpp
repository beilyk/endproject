#include "base_message.h"

base_message::base_message(int messageId, int messageType)
{
	this->messageId = messageId;
		if (messageType == 1 || messageType == 2)
			this->messageType = messageType;
}

void base_message::parseBack()
{

}

unsigned char* base_message::getMessageBuffer()
{
	return this->messageBuffer;
}
