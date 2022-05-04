#pragma once
#include <stdlib.h>
#include "Camera.h"
#include "read_config.h"
	class Simulator
	{
		
		Camera camera_vec[3];
	public:
		read_config rc;
		void run();
		Simulator();
		
	};


