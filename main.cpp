
#include<iostream>

#include "Simulator.h"
//read json
#include "config.json"
#include <fstream>//עבור קריאת text
//void main() {
//	Simulator s = Simulator::Simulator();
//	s.run();
//	getchar();
//	/*Camera*c = new Camera();
//	(*c).run();*/
//	/*std::thread t1((*c).run());
//	std::this_thread::sleep_for(15s);
//	std::thread t2(c.stop());
//	(*c).run();*/
//
//}

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment (lib, "Ws2_32.lib")
#include <iostream>
#include <string.h>
#include <sstream>
#include <WinSock2.h>
#include <WS2tcpip.h>
using namespace std;

#include"Camera.h";
int main()
{
	Simulator s = Simulator::Simulator();
	
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		cout << "Winsock Connection Failed!" << endl;
		exit(1);
	}

	string getInput = "";
	SOCKADDR_IN addr;
	int addrLen = sizeof(addr);
	IN_ADDR ipvalue;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(s.rc.get_server_port());
	addr.sin_family = AF_INET;

	SOCKET connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(connection, (SOCKADDR*)&addr, addrLen) == 0) {
		cout << "Connected!" << endl;
		
		s.run();
		send(connection, "aaaa", 5, 0);
		char x;
		std::cin >> x;
		
		closesocket(connection);
		WSACleanup(); 
		exit(0);
	
	}
	else {
		cout << "Error Connecting to Host" << endl;
		exit(1);
	}
	
	return 0;
}