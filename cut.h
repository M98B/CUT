//Main program definitions
#include "stdio.h"
#include "pthread.h"
#include "string.h"

typedef void *(*thread_routine)(void *);

void* reader_callback();
void* analyser_callback();
void* printer_callback();

typedef struct _Thread
{
    pthread_t* p;
    thread_routine callback;
} Thread;

typedef struct _Cpu_stat
{
    /* data */
} Cpu_stat;


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



#define THREAD_NUM  sizeof(threads)/sizeof(Thread)
