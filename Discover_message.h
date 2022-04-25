#pragma once

#include "base_message.h"
	class Discover_message :public base_message
	{
	protected:
		float distance;// (500 - 10000)
		float angle;//(0 - 360)
		float speed;//(0 - 1000)
	public:
		void parseMessage();
		void parseBack();
		void print();
		Discover_message(int messageId, int messageType, float distance, float angle, float speed);
		Discover_message();
		~Discover_message();
	};


