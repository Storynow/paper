#include"/root/Shark/shark.h"

void *subpth(void *arg);

void f1(void *arg);
void f2(void *arg);
void f3(void *arg);

int main(int argc, char **argv)
{
    pthread_t pthid;
    if ((pthread_create(&pthid,NULL,subpth,NULL))!=0) {printf("hhh\n"); return -1;}

    sleep(1);
    // pthread_cancel(pthid);

    // sleep(10);



    return 0;
}

void *subpth(void *arg)
{
    int sockid = 547498;  
    pthread_cleanup_push(f1,(void *)(size_t)&sockid);
    pthread_cleanup_push(f2,NULL);
    pthread_cleanup_push(f3,NULL);

    return 0;
    pthread_exit(0);
    for (int i=0;i<3;++i) { sleep(1); printf("sleep....%d\n", i+1); }

    pthread_cleanup_pop(0);
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(0);

    pthread_exit(0);
}

void f1(void *arg)
{
    printf("f1......%d\n", *(int *)arg);
}
void f2(void *arg)
{
    printf("f2......\n");
}
void f3(void *arg)
{
    printf("f3......\n");
}
