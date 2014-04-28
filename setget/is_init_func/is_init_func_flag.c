#include "is_init_func_flag.h"
char is_init = 0;
void setflag_is_init_func(void)
{
    is_init = 1;
}

char getflag_is_init_func(void)
{
    return is_init;
}

void clrflag_is_init_func(void)
{
    is_init = 0;
}
