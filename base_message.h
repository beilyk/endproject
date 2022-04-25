#pragma once
class base_message
{
protected:
	unsigned char* messageBuffer;
	int messageId;
	int messageType;
public:
	virtual void parseMessage() = 0;
	virtual void parseBack() = 0;
	virtual void print() = 0;
	unsigned char* getMessageBuffer();
	base_message(int messageId, int messageType);
	base_message();
	~base_message();
};

