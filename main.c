#include "stdlib.h"
#include "cut.h"
#include "unistd.h"


pthread_t reader;
pthread_t analyser;
pthread_t printer;

Thread threads[] =
{
    {&reader,   reader_callback  },
    {&analyser, analyser_callback},
    {&printer,  printer_callback },
};

#define THREAD_NUM  sizeof(threads)/sizeof(Thread)

int main()
{
    unsigned int num_cores = 12;

    for (size_t i = 0; i < max_threads; i++)
    {
        pthread_create( threads[i].p,
                        NULL,
                        threads[i].callback,
                        &num_cores);
    }

    for (size_t i = 0; i < max_threads; i++)
    {
        pthread_join(*threads[i].p, NULL);
    }
    
    return 0;
}
