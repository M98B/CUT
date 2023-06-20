//Main program definitions
#ifndef CUT_HEADER
#define CUT_HEADER

#include "stdio.h"
#include "stdlib.h"
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
    unsigned long t_user, t_nice, t_system, t_idle, t_iowait, t_irq;
} Cpu_stat;


enum thread_idx
{
    cut_reader_pthead_idx,
    cut_analyser_pthead_idx,
    cut_printer_pthead_idx,
    max_threads
};
#endif
