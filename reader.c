#include "cut.h"


void* reader_callback()
{
    char line[2024];
    int retval = 1;
    unsigned long t_user, t_nice, t_system, t_idle, t_iowait, t_irq;
    FILE* stat = fopen("/proc/stat", "rb");
    if (NULL != stat)
    {
        
        //read /proc/stat untill we encounter an error or all CPU lines have been read
        while (fgets(line, sizeof(line), stat) && retval) 
        {
            //use sscanf to parse the line 
            retval = sscanf(line, "cpu %lu %lu %lu %lu %lu %lu", &t_user, &t_nice, &t_system, &t_idle, &t_iowait, &t_irq);
            printf("%lu %lu %lu %lu %lu %lu\n", t_user, t_nice, t_system, t_idle, t_iowait, t_irq);
        }
        
    }
    fclose(stat);
    return 0;
}