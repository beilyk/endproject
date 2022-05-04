#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "read_config.h"
read_config::read_config() {
    string line;
    ifstream myfile("config.txt");
    if (myfile.is_open())
    {
        int place;
        if (getline(myfile, line))
        {
            place = line.find(':', 0);
            num_camera = stoi(line.substr(place + 1));
        }
        if (getline(myfile, line))
        {
           
            place = line.find(':', 0);
            num_message = stoi(line.substr(place+1));
           
        }
        if (getline(myfile, line))
        {
           
            place = line.find(':', 0);
            std::string server_ip = line.substr(place + 1);
            
        }
        if (getline(myfile, line))
        {
            
            place = line.find(':', 0);
            server_port = stoi(line.substr(place + 1));
            
        }
        myfile.close();
    }

    else cout << "Unable to open file";

	
}
int read_config::get_num_camera() {
    return num_camera;
}
int read_config::get_num_message() {
    return num_message;
}
std::string read_config::get_server_ip() {
    return server_ip;
}
int read_config::get_server_port() {
    return server_port;
}