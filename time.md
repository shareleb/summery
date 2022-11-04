获得从新纪元到现在的秒数
#include<time.h>
time_t time(time_t * time);
// time_t 在头文件#include<time.h>中，在大多数unix系统上，是一个简单的c语言整形。  typedef long time_t;
// time为非NULL时，也会写入到time中。 失败返回-1 设置errno 为EFAULT. 成功返回time_t


的微妙级精度支持
#include<sys/time.h>
struct timeval {
    time_t tv_sec;        //秒
    suseconds_t tv_usec; //微妙
};
#include<sys/time.h>
int gettimeofday(struct timeval * tv , struct timezone * tz);
//会将当前时间放到timeval中，tz已经废弃，总穿NULL, 成功返回0 失败为-1,设置errno 为EFAULT.


纳秒级别精度支持
#include<time.h>
struct timespec {
    time_t tv_sec;
    long tv_nsec;
};
#include<time.h>
int clock_gettime(clockid_t clock_id, struct timespec * ts); 
