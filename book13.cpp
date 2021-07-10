#include"/root/Shark/shark.h"

void *_hd1(void *arg);
void *_hd2(void *arg);


int main(int argc, char **argv)
{
    pthread_t pthid1, pthid2;
    
    size_t val = 10;
    
    if (pthread_create(&pthid1, NULL,_hd1, (void *)val) != 0) { printf("HERE.\n"); return -1; }
    ++val;
    if (pthread_create(&pthid2, NULL,_hd2, (void *)val) != 0) { printf("HERE.\n"); return -1; }
    
    // printf("pthid=%lu\n", pthid);

    // printf("等待子进程退出...\n");
    sleep(1);

    printf("done.\n");

    return 0;
}

void *_hd1(void *arg)
{
    printf("1..sleep...%ld\n", (size_t)arg);
    printf("sleep ok.\n");

    return (void *)0;
}

void *_hd2(void *arg)
{
    printf("2..sleep...%ld\n", (size_t)arg);
    printf("sleep ok.\n");

    return (void *)0;
}
