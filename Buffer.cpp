#include "Buffer.h"
#include <cstdlib>
std::mutex foo, bar;

void task_a() {
   
    std::lock(foo, bar);
    std::cout << "task a\n";
    foo.unlock();
    bar.unlock();
}



void Buffer::addToBuffer(base_message**message) {
    while (!foo.try_lock());
        std::cout << "task a\n";
    
    
    if (!buffer) {
      
        buffer = (char**)malloc(sizeof(char*) * N);
      
    }
    else{
        
          buffer = (char**)realloc(buffer, sizeof(char*)*N*index);
          
    }
      for (int i = 0; i < N; i++) {
          message[i]->parseBack();
         
          buffer[index++] = (char*)message[i]->getMessageBuffer();
          
      }
      
      foo.unlock();
}
char** Buffer::getBuffer() {
    return buffer;
}
void Buffer::cleanBuffer() {
    std::cout << "clean buffer\n";
   for (int i = 0; i < this->index; i++) {
        delete(buffer[i]);
   }
    buffer = nullptr;
   index = 0;

}
Buffer::Buffer(){
    index =0;
    while (!foo.try_lock());
    buffer = nullptr;
    foo.unlock();
}
Buffer::~Buffer() {
    while (!foo.try_lock()) {
        
    }
    
    for (int i = 0; i < index; i++) {
        delete(buffer[i]);
    }
    if (buffer) {
        free(buffer);
    }
    foo.unlock();
  
    index = 0;
}
