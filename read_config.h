#pragma once
#include <string>
class read_config
	
{
private:
	int num_camera;
	int num_message;
	std::string  server_ip;
	int server_port;
	
	
public:
	
	 int get_num_camera();
	 int get_num_message();
	 std::string  get_server_ip();
	 int get_server_port();
	 read_config();
};

