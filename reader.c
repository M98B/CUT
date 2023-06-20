#include "cut.h"


void* reader_callback(void* p)
{
    if (NULL == p)
    {
        return 0;
    }

    unsigned int num_cores =  *((unsigned int*) p);
    printf("%u num cores\n", num_cores);
    char line[2024];
    int retval = 1;
    Cpu_stat*  parsed = malloc(sizeof(Cpu_stat) * 12);
    FILE* stat = fopen("/proc/stat", "rb");
    if (NULL != stat)
    {
        
        //read /proc/stat untill we encounter an error or all CPU lines have been read
        while (fgets(line, sizeof(line), stat) && retval) 
        {
            //use sscanf to parse the line 
            retval = sscanf(line, "cpu %lu %lu %lu %lu %lu %lu",
                    &parsed->t_user, &parsed->t_nice,  &parsed->t_system,
                    &parsed->t_idle, &parsed->t_iowait, &parsed->t_irq);

            printf("%5lu %5lu %5lu %5lu %5lu %5lu\n", parsed->t_user, parsed->t_nice,
              parsed->t_system, parsed->t_idle, parsed->t_iowait, parsed->t_irq);
        }
        
    }
    free(parsed);
    fclose(stat);
    return 0;
}