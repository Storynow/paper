#include"/root/Shark/shark.h"

void hdfunc(const int sig);

    /*
     *  signal( 2, hdfunc);
     *  signal(15, hdfunc);
     *
     *  struct sigaction stact;
     *  memset(&stact, 0, sizeof(struct sigaction));
     *  stact.sa_handler = hdfunc;      //  指定信号的处理函数
     *  sigaddset(&stact.sa_mask, 15);   //  指定需要阻塞的信号
     *  stact.sa_flags = SA_RESTART;    // 如果信号中断了进程的某个系统调用，则系统自动启用该系统调用
     *  sigaction(2 , &stact, NULL);   //  设置信号 2的处理行为
     *  sigaction(15, &stact, NULL);   //  设置信号15的处理行为
     *  
     * */

int main(int argc, char **argv)
{
    
    //CLOSE_ALL_SIGNAL_IO;
    for (int i = 1; i <= 64; ++i)
        signal(i, SIG_IGN);

    signal(34, hdfunc);
    signal(64, hdfunc);

    // struct sigaction stact;
    // memset(&stact, 0, sizeof(struct sigaction));
    // stact.sa_handler = hdfunc;      // 指定信号的处理函数
    // sigaddset(&stact.sa_mask, 15);  // 指定需要阻塞的信号
    // stact.sa_flags = SA_RESTART;    // 如果信号中断了进程的某个系统调用，则系统自动启用该系统调用
    // sigaction(2 , &stact, NULL);    // 设置信号 2的处理行为
    // sigaction(15, &stact, NULL);    // 设置信号15的处理行为

    // char name[100]; memset(name, 0, sizeof(name));
    // scanf("%s", name);
    // printf("=%s=\n", name);

    // return 0;

    for (int i = 0; i < 100; ++i)
    {
        printf("i = %d\n", i);
    
        sleep(1);
    }

    return 0;
}


void hdfunc(const int sig)
{
    for (int i = 1; i <= 5; ++i)
    {
        printf("sig(%d)......%d\n", sig, i);
        sleep(1);
    }

    return ;
}
