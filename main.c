#include "stdlib.h"
#include "cut.h"
#include "unistd.h"

Thread threads[] =
{
    {&reader,   reader_callback  },
    {&analyser, analyser_callback},
    {&printer,  printer_callback },
};

int main()
{

    for (size_t i = 0; i < max_threads; i++)
    {
        pthread_create( threads[i].p,
                        NULL,
                        threads[i].callback,
                        NULL);
    }

    for (size_t i = 0; i < max_threads; i++)
    {
        pthread_join(*threads[i].p, NULL);
    }
    
    
    return 0;
}
