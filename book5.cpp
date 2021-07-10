#include"/root/Shark/shark.h"

int main(int argc, char **argv)
{
    char buffer[301]; memset(buffer, 0, sizeof(buffer));
    printf("%s\n", getcwd(buffer, 300));

    memset(buffer, 0, sizeof(buffer));
    chdir("/home/yangjiayin/local");
    printf("%s\n", getcwd(buffer, 300));

    
    // chdir("/tmp");
    // mkdir("/tmp/lisiyu", 0755);
    chdir("/root/paper");
    opendir("/root/paper");


    return 0;
}
