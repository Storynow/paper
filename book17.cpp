#include"/root/Shark/shark.h"

void *func(void *arg);
void hd(int sig);

int main(int argc, char **argv)
{
    // CLOSE_ALL_SIGNAL_IO;
    signal(2, hd);

    pthread_t pthid;
    if ((pthread_create(&pthid,NULL,func,NULL)) != 0) { printf("Error.\n"); return -1; }

    int iret, ists;
    printf("waiting....\n");

    
    for(int i=1;i<=7;++i) { sleep(1); printf("main.....................%d\n", i); }

    iret = pthread_join(pthid,(void**)&ists);
    printf("DONE.....%d  /  %d\n", iret, ists);

    sleep(1);

    return 0;
}

void *func(void *arg)
{
    for(int i=1;i<=10;++i) { sleep(1); printf("func...%d\n", i); }
    
    pthread_exit(0);
}

void hd(int sig)
{
    for (int i=1;i<=3;++i) { sleep(1); printf("sig(%d)...%d\n", sig, i); }
}
