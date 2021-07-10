#include"/root/Shark/shark.h"

// struct dirent
// {
//    long d_ino;                    // inode number 索引节点号
//    off_t d_off;                   // offset to this dirent 在目录文件中的偏移
//    unsigned short d_reclen;     // length of this d_name 文件名长
//    unsigned char d_type;         // the type of d_name 文件类型
//    char d_name [NAME_MAX+1];    // file name文件名，最长255字符
// };


int main(int argc, char **argv)
{
    DIR *dir;
    if ((dir = opendir("/root/paper")) == 0) { printf("HERE.\n"); return -1; }

    struct dirent *stdinfo = 0;
    while (1)
    {
        if ((stdinfo = readdir(dir)) == 0) break;
        printf("name = %s, type = %d\n", stdinfo->d_name, stdinfo->d_type);
    }

    closedir(dir);


    return 0;
}
