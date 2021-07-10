#include"/root/Shark/shark.h"


// typedef long time_t;
// struct tm * localtime(const time_t *);

/* struct tm
 * {
 *   int tm_sec;     // 秒：取值区间为[0,59]
 *   int tm_min;     // 分：取值区间为[0,59]
 *   int tm_hour;    // 时：取值区间为[0,23]
 *   int tm_mday;    // 日期：一个月中的日期：取值区间为[1,31]
 *   int tm_mon;     // 月份：（从一月开始，0代表一月），取值区间为[0,11]
 *   int tm_year;    // 年份：其值等于实际年份减去1900
 *   int tm_wday;    // 星期：取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推
 *   int tm_yday;    // 从每年的1月1日开始的天数：取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推
 *   int tm_isdst;   // 夏令时标识符，该字段意义不大，我们不用夏令时。
 * };
 */

int main(int argc, char **argv)
{
    time_t now;
    now = time(0);
    printf("%lu\n", now);

    struct tm *ptm = 0;
    ptm = localtime(&now);
    
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", \
            ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);

    return 0;
}
