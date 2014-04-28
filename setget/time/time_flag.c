#include "time_flag.h"
uint8 timeval = 0;
void setflag_time(void)
{
    timeval = 1;
}

uint8 getflag_time(void)
{
    return timeval;
}

void clrflag_time(void)
{
    timeval = 0;
}
