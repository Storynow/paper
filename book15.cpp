#include"/root/Shark/shark.h"

void *_hd(void *arg);

int main(int argc, char **argv)
{
    pthread_t pthid;

    if ((pthread_create(&pthid, NULL, _hd, NULL))!= 0) {printf("error!\n"); return -1;}

    usleep(1e3); pthread_cancel(pthid);

    int ret;
    int ff = pthread_join(pthid,(void**)&ret);
    //pthread_detach(pthid);

    printf("ret = %d,,, ff = %d\n", ret, ff);

    sleep(1);



    return 0;
}

void *_hd(void *arg)
{
    // pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
    // pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    // pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    int j = 0;
    for (int i = 0; i < 5e5; ++i)
    {
        j++; ++j; --j;
        pthread_testcancel();
    }
    printf("j = %d\n", j);

    pthread_exit(0);
}
