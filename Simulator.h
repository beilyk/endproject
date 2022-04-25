#pragma once

#include "base_message.h"
#include <stdlib.h>
#include "Status_message.h"
#include "Discover_message.h"
#include "Camera.h"

	class Simulator
	{
	/*protected:
		base_message* buffer[10];*/

	private:
		Camera*camera_vec[3];

	public:
		Status_message* createStatusMessage();
		Discover_message* createDiscoverMessage();
		//void generateAndSendMessage();
	};


