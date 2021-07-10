#include"/root/Shark/shark.h"

void *_hd1(void *arg);
void *_hd2(void *arg);

int val = 0;

int main(int argc, char **argv)
{
    pthread_t pthid1, pthid2;
    
    if (pthread_create(&pthid1, NULL,_hd1, NULL) != 0) { printf("HERE.\n"); return -1; }
    if (pthread_create(&pthid2, NULL,_hd2, NULL) != 0) { printf("HERE.\n"); return -1; }
    
    // printf("pthid=%lu\n", pthid);

    printf("等待子进程退出...\n");

    pthread_join(pthid1, NULL);
    pthread_join(pthid2, NULL);

    printf("done.\n");

    return 0;
}

void *_hd1(void *arg)
{
    for (int i = 1; i <= 5; ++i) { sleep(1); ++val; printf("1..sleep...%d\n", val); }
    printf("sleep ok.\n");
    return (void *)0;


}
void *_hd2(void *arg)
{
    for (int i = 1; i <= 10; ++i) { sleep(1); ++val; printf("2..sleep...%d\n", val); }
    printf("sleep ok.\n");

    return 0;
}
