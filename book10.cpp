#include"/root/Shark/shark.h"

int main(int argc, char **argv)
{
    int shmid;
    if ((shmid = shmget((key_t)0x5050, 1024, 0640|IPC_CREAT))==-1)
    { printf("shmat(0x5050) failed.\n");}

    char *p = 0;
    p = (char*) shmat(shmid, 0, 0);

    printf("%s\n", p);
    sprintf(p, "%d", getpid());
    printf("%s\n", p);

    shmdt((void *)p);

    shmctl(shmid, IPC_RMID, 0);


    return 0;
}
