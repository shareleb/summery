/*************************************************************************
	> File Name: timeutil.h
	> Author: 
	> Mail: 
	> Created Time: 一  7/11 11:21:19 2022
 ************************************************************************/

#ifndef _TIMEUTIL_H
#define _TIMEUTIL_H

#include<sys/time.h>

inline uint64_t timeNow() {
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}





#endif
