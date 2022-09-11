//Main program definitions
#include "stdio.h"
#include "pthread.h"

typedef void *(*thread_routine)(void *);

typedef struct _Thread
{
    pthread_t* p;
    thread_routine callback;
} Thread;

void* reader_callback()
{
    printf("Reading\n");
    return 0;
}
void* analyser_callback()
{
    printf("Analysing\n");
    return 0;
}
void* printer_callback()
{
    printf("Printing\n");
    return 0;
}

pthread_t reader;
pthread_t analyser;
pthread_t printer;

enum thread_idx
{
    cut_reader_pthead_idx,
    cut_analyser_pthead_idx,
    cut_printer_pthead_idx,
    max_threads
};

Thread threads[] =
{
    {&reader,   reader_callback  },
    {&analyser, analyser_callback},
    {&printer,  printer_callback },
};

#define THREAD_NUM  sizeof(threads)/sizeof(Thread)
