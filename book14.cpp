#include"/root/Shark/shark.h"

void *_hd1(void *arg);


int main(int argc, char **argv)
{
    pthread_t pthid1, pthid2;
    
    // pthread_join(pthid1, NULL);

    /*
     * pthread_attr_t attr;
     * pthread_attr_init(&attr);
     * pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
     * pthread_create(&phid, &attr, pth_main, NULL);
     */
    
    if (pthread_create(&pthid1, NULL,_hd1, NULL) != 0) { printf("HERE.\n"); return -1; }
    // if (pthread_create(&pthid2, NULL,_hd2, (void *)val) != 0) { printf("HERE.\n"); return -1; }

    pthread_detach(pthid1);
    
    usleep(1e3);
    int result = pthread_join(pthid1, NULL);
    printf("xxxxxxxxxxxxxx%d\n", result);

    sleep(2);


    printf("done.\n");

    return 0;
}

void *_hd1(void *arg)
{
    // pthread_detach(pthread_self());
    printf("1..sleep...%ld\n", (size_t)arg);
    printf("sleep ok.\n");

    return (void *)0;
}
