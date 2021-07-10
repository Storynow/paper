#include"/root/Shark/shark.h"

int main(int argc, char **argv)
{
    // 关闭所有的信号与IO
    CLOSE_ALL_SIGNAL_IO;

    if (fork() != 0)
    {
        sleep(20);
    }
    else
    {
        ;
    }


    return 0;
}
