#include "FirstAlarm_flag.h"
uint8 FirstAlarm_Flag = 0;
void setflag_FirstAlarm(void)
{
    FirstAlarm_Flag = 1;
}

uint8 getflag_FirstAlarm(void)
{
    return FirstAlarm_Flag;
}

void clrflag_FirstAlarm(void)
{
    FirstAlarm_Flag = 0;
}
