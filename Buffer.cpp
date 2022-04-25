#include "Buffer.h"
#include "base_message.h"
#include <cstdlib>

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
}
Buffer::~Buffer() {
    free(buffer);
}

