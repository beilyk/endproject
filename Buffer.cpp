#include "Buffer.h"
#include "base_message.h"
#include <cstdlib>
#include <iostream>

void Buffer::addToBuffer(base_message*message) {
        
	    char* vec_message =(char*) message->getMessageBuffer();
  
        buffer = (char**)realloc(buffer, sizeof(char*));
        buffer[index++] = vec_message;

}
char** Buffer::getBuffer() {
    return buffer;
}
void Buffer::cleanBuffer() {
    buffer = NULL;
}
Buffer::Buffer(){
    index = 0;
    buffer = (char**)malloc( sizeof(char*));
}
Buffer::~Buffer() {
    free(buffer);
}

