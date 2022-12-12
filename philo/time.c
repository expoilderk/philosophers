#include "philo.h"

/*long get_time_now()
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec - timestamp.tv_sec) * 1000 + (current_time.tv_usec - timestamp.tv_usec) / 1000;
}*/

long get_time(struct timeval timestamp)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec - timestamp.tv_sec) * 1000 + (current_time.tv_usec - timestamp.tv_usec) / 1000;
}
