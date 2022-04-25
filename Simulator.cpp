#include "Simulator.h"

Status_message* Simulator::createStatusMessage()
{
	static int id = 1;
	id++;
	Status_message* sm = new Status_message(id, 1, rand() % 3 + 1);
	return sm;
}

Discover_message* Simulator::createDiscoverMessage()
{
	static int id = 100;
	id++;
	Discover_message* dm = new Discover_message(id, 2, rand() % 9500 + 500, rand() % 361, rand() % 1001);
	return dm;
}

//void Simulator::generateAndSendMessage()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		(rand() % 2 + 1 == 1) ? buffer[i] = createStatusMessage() : buffer[i] = createDiscoverMessage();
//		buffer[i]->print();
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		buffer[i]->parseBack();
//		buffer[i]->parseMessage();
//		buffer[i]->print();
//		buffer[i]->~base_message();
//	}
//}
