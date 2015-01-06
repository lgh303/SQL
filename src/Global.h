#ifndef __GLOBAL__H__
#define __GLOBAL__H__
#include <ctime>
#include <cstring>

time_t GetCurrentTime();

struct ptrCmp
{
    bool operator()( const char * s1, const char * s2 ) const
    {
        return strcmp( s1, s2 ) < 0;
    }
};

#endif
