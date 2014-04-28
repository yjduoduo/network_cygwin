#include "date_flag.h"
void setflag_date(void)
{
    dateval = 1;
}

uint32 getflag_date(void)
{
    return dateval;
}

void clrflag_date(void)
{
    dateval = 0;
}
