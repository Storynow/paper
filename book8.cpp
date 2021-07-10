#include"/root/Shark/shark.h"

/* 
 * #define R_OK 4     // R_OK 只判断是否有读权限
 * #define W_OK 2     // W_OK 只判断是否有写权限
 * #define X_OK 1     // X_OK 判断是否有执行权限
 * #define F_OK 0     // F_OK 只判断是否存在
 *
 * struct stat
 * {
 *   dev_t st_dev;   // device 文件的设备编号
 *   ino_t st_ino;   // inode 文件的i-node
 *   mode_t st_mode;   // protection 文件的类型和存取的权限
 *   nlink_t st_nlink;   // number of hard links 连到该文件的硬连接数目, 刚建立的文件值为1.
 *   uid_t st_uid;   // user ID of owner 文件所有者的用户识别码
 *   gid_t st_gid;   // group ID of owner 文件所有者的组识别码
 *   dev_t st_rdev;  // device type 若此文件为设备文件, 则为其设备编号
 *   off_t st_size;  // total size, in bytes 文件大小, 以字节计算
 *   unsigned long st_blksize;  // blocksize for filesystem I/O 文件系统的I/O 缓冲区大小.
 *   unsigned long st_blocks;  // number of blocks allocated 占用文件区块的个数, 每一区块大小为512 个字节.
 *   time_t st_atime;  // time of lastaccess 文件最近一次被存取或被执行的时间, 一般只有在用mknod、 utime、read、write 与tructate 时改变.
 *   time_t st_mtime;  // time of last modification 文件最后一次被修改的时间, 一般只有在用mknod、 utime 和write 时才会改变
 *   time_t st_ctime;  // time of last change i-node 最近一次被更改的时间, 此参数会在文件所有者、组、 权限被更改时更新
 * };
 */


int main(int argc, char **argv)
{
    if (access("/root/paper/test.cpp", F_OK) != 0 )  { printf("HERE.\n");return -1; }

    struct stat ststat;

    if (stat("/root/paper/book1.cpp", &ststat) != 0) return -1;

    struct tm *ptm = 0;
    ptm = localtime(&ststat.st_mtime);

    printf("%04d-%02d-%02d %02d:%02d:%02d\n", \
            ptm->tm_year+1900, ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
    

    return 0;

}
