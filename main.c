#include "stdlib.h"
#include "cut.h"

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < max_threads; i++)
    {
        pthread_create( threads[i].p,
                        NULL,
                        threads[i].callback,
                        NULL);
    }
    while (1)
    {
        /* code */
    }
    
    return 0;
}
