#include "stdio.h"
#include "pthread.h"

void* hello_world_thread (){
    printf("hello world\n");
    return 0;
}


int main(int argc, char const *argv[])
{
    pthread_t hello_world;
    pthread_create(&hello_world, NULL, hello_world_thread, NULL);
    pthread_join(hello_world, NULL);
    return 0;
}
