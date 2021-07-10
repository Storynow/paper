// Email:  sisi547498@gmail.com
// Auther：杨家印

//////* $Begin shark.h */////////////////////////////
#ifndef __SHARK_H__
#define __SHARK_H__

#include"__cmp_public.h"

/////////////////* $Begin MACRO *//////////// 


// 禁止类的默认赋值操作和拷贝构造
#define DISALLOW_COPY_AND_ASSIGN( TypeName ) \
    TypeName( const TypeName & ); \
    TypeName operator=( const TypeName & );


// LOG 调试日志
#ifdef DEBUG

#define LOG(frm, args...) { \
    printf("\033[0;31m[%s : %d : %s]\033[0;32m: ", __FILE__, __LINE__ , __func__); \
    printf(frm, ##args); \
    printf("\033[0m\n"); \
}

#else

#define LOG(frm, args...)

#endif

#define CLOSE_ALL_SIGNAL \
    for ( int i = 1; i <= 31; ++i) {signal(i, SIG_IGN); close(i);}


/////////////////* $End MACRO *///////////////


/////////////////* $Begin FUNCTION *///////////// 


// 从左边开始删除 num 个字符，(0 <= num <= len),缺省为 1
// 返回值: 返回原字符串首地址 src
// char *LeftDeleteNum(char *src, int num = 1);
char *LeftDeleteNum(char *src, int num = 1);


// 从右边开始删除 num 个字符，(0 <= num <= len),缺省为 1
// 返回值: 返回原字符串首地址 src
// char *RightDeleteNum(char *src, int num = 1);
char *RightDeleteNum(char *src, int num = 1);


// 2021/04/21/22:13
// 把一个字符串开头的字符删除，直到遇到其他字符或该字符串已经删除到末尾
// 缺省字符为 '\n',
// 返回值: 源字符串的首地址
// char *LeftDestroyChr( char *src, char chr = '\n' );
char *LeftDestroyChr( char *src, char chr = '\n' );


// 2021/04/21/22:13
// 把一个字符串末尾的字符删除，直到遇到其他字符或该字符串已经删除到开头
// 默认字符为 '\n',
// 返回值: 返回字符串的首地址
// char *RightDestroyChr( char *src, char chr = '\n' );
char *RightDestroyChr( char *src, char chr = '\n' );


// 2021/04/24/21:21
// 将一个字符串的字符从 开始 开始连续删除字符,直到遇到某一个字符 chr 为止,
// 该字符 chr 将会被保留,返回值为源字符串 src 的地址
// char *LeftDisappearUntilChr( char *src, char chr = '\n' );
char *LeftDisappearUntilChr( char *src, char chr = '\n' );


// 2021/04/24/20:05
// 将一个字符串的字符从 末尾 开始连续删除字符,直到遇到某一个字符 chr 为止,
// 该字符 chr 将会被保留,返回值为源字符串 src 的地址
// char *RightDisappearUntilChr( char *src, char chr = '\n' );
char *RightDisappearUntilChr( char *src, char chr = '\n' );


// 2021/06/17/15:42
// 将一个字符串中的空白字符删掉，
// space (' '), tab ('\t'), carriage return ('\r'), newline ('\n'), vertical tab ('\v') and formfeed ('\f').
// 返回字为字符串的首地址
// char *StrNoWhiteSpace(char *src);
char *StrNoWhiteSpace(char *src);


// 2021/06/29/21:33
// 去除字符串左边的空白字符
// 参数 src 为源字符串
// char *LeftNoWhiteSpace(char *src);
char *LeftNoWhiteSpace(char *src);


// 2021/06/29/21:33
// 去除字符串右边的空白字符
// 参数 src 为源字符串
// char *RightNoWhiteSpace(char *src);
char *RightNoWhiteSpace(char *src);


// 2021/06/17/22:10
// 删除字符串中的子字符串
// int num 为预留接口,默认不填,
// 从子字符串开始的地方开始删除 num 个字符，
// num 对 strlen 的数取模, 正数有效
// char *StrStrDelete(char *src, char *sub, int num = 0);
char *StrStrDelete(char *src, char *sub, int num = 0);


// 2020/06/18/15:36
// 两个字符串及其中的字符将会被保留下来
// 将匹配到的字符串中间内容提取出来,如果没有的话不做处理
// 第一个参数 为要处理的字符串地址
// 第二个参数 为第一个子字符串地址
// 第三个参数 为第二个子字符串地址
// 第四个参数 为贪婪模式,默认为非贪婪模式
// 第五个参数 匹配到 num 个终止, 小于等于 0 为全贪婪
// char *StrStrRemain(char *src, const char *start, const char *end, const bool flag = false, const int num = 0);
char *StrStrRemain(char *src, const char *start, const char *end, const bool flag = false, const int num = 0);


// 打开文件。
// FOPEN函数调用fopen库函数打开文件，如果文件名中包含的目录不存在，就创建目录。
// FOPEN函数的参数和返回值与fopen函数完全相同。
// 在应用开发中，用FOPEN函数代替fopen库函数。
// FILE *FOPEN(const char *filename,const char *mode);
FILE *FOPEN(const char *filename,const char *mode);


// 根据绝对路径的文件名或目录名逐级的创建目录。
// pathorfilename：绝对路径的文件名或目录名。
// bisfilename：说明pathorfilename的类型，true-pathorfilename是文件名，否则是目录名，缺省值为true。
// 返回值：true-创建成功，false-创建失败，如果返回失败，原因有大概有三种情况：1）权限不足； 2）pathorfilename参数不是>合法的文件名或目>录名；3）磁盘空间不足。
// bool MKDIR(const char *filename,bool bisfilename = true);
bool MKDIR(const char *filename,bool bisfilename = true);


// 安全的snprintf函数。
// 将可变参数(...)按照fmt描述的格式输出到dest字符串中。
// dest：输出字符串，不需要初始化，在SNPRINTF函数中会对它进行初始化。
// destlen：输出字符串dest占用内存的大小，如果格式化后的字符串内容的长度大于destlen-1，后面的内容将丢弃。
// n：把格式化后的字符串截取n-1存放到dest中，如果n>destlen，则取destlen-1。
// fmt：格式控制描述。
// ...：填充到格式控制描述fmt中的参数。
// 返回值：格式化后的内容的长度，程序员一般不关心返回值。
// int SNPRINTF(char *dest,const size_t destlen,size_t n,const char *fmt,...);
int SNPRINTF(char *dest,const size_t destlen,size_t n,const char *fmt,...);


// 打开文件。
// FOPEN函数调用fopen库函数打开文件，如果文件名中包含的目录不存在，就创建目录。
// FOPEN函数的参数和返回值与fopen函数完全相同。
// 在应用开发中，用FOPEN函数代替fopen库函数。
FILE *FOPEN(const char *filename,const char *mode);


// 从文本文件中读取一行。
// fp：已打开的文件指针。
// buffer：用于存放读取的内容，buffer必须大于readsize+1，否则可能会造成读到的数据不完整或内存的溢出。
// readsize：本次打算读取的字节数，如果已经读取到了行结束标志，函数返回。
// endbz：行内容结束的标志，缺省为空，表示行内容以"\n"为结束标志。
// 返回值：true-成功；false-失败，一般情况下，失败可以认为是文件已结束。
bool FGETS(const FILE *fp,char *buffer,const int readsize,const char *endbz=0);


// 把字符串中的小写字母转换成大写，忽略不是字母的字符。
// str：待转换的字符串，支持char[]和string两种类型。
void ToUpper(char *str);
void ToUpper(string &str);


/*
    取操作系统的时间。
    stime：用于存放获取到的时间字符串。
    timetvl：时间的偏移量，单位：秒，0是缺省值，表示当前时间，30表示当前时间30秒之后的时间点，-30表示当前时间30秒之前的>时间点。
    fmt：输出时间的格式，fmt每部分的含义：yyyy-年份；mm-月份；dd-日期；hh24-小时；mi-分钟；ss-秒，
    缺省是"yyyy-mm-dd hh24:mi:ss"，目前支持以下格式：
    "yyyy-mm-dd hh24:mi:ss"
    "yyyymmddhh24miss"
    "yyyy-mm-dd"
    "yyyymmdd"
    "hh24:mi:ss"
    "hh24miss"
    "hh24:mi"
    "hh24mi"
    "hh24"
    "mi"
    注意：
        1）小时的表示方法是hh24，不是hh，这么做的目的是为了保持与数据库的时间表示方法一致；
        2）以上列出了常用的时间格式，如果不能满足你应用开发的需求，请修改源代码timetostr函数增加更多的格式支持；
        3）调用函数的时候，如果fmt与上述格式都匹配，stime的内容将为空。
        4）时间的年份是四位，其它的可能是一位和两位，如果不足两位，在前面补0。
*/
void LocalTime(char *stime,const char *fmt=0,const int timetvl=0);


// 把整数表示的时间转换为字符串表示的时间。
// ltime：整数表示的时间。
// stime：字符串表示的时间。
// fmt：输出字符串时间stime的格式，与LocalTime函数的fmt参数相同，如果fmt的格式不正确，stime将为空。
void timetostr(const time_t ltime,char *stime,const char *fmt=0);


// 安全的strcpy函数。
// dest：目标字符串，不需要初始化，在STRCPY函数中会对它进行初始化。
// destlen：目标字符串dest占用内存的大小。
// src：原字符串。
// 返回值：目标字符串dest的地址。
char *STRCPY(char* dest,const size_t destlen,const char* src);


// 安全的strncpy函数。
// dest：目标字符串，不需要初始化，在STRNCPY函数中会对它进行初始化。
// destlen：目标字符串dest占用内存的大小。
// src：原字符串。
// n：待复制的字节数。
// 返回值：目标字符串dest的地址。
char *STRNCPY(char* dest, size_t destlen,const char* src,size_t n);


// 安全的strcat函数。
// dest：目标字符串。
// destlen：目标字符串dest占用内存的大小。
// src：待追加的字符串。
// 返回值：目标字符串dest的地址。
char *STRCAT(char* dest,const size_t destlen,const char* src);


// 安全的strncat函数。
// dest：目标字符串。
// destlen：目标字符串dest占用内存的大小。
// src：待追加的字符串。
// n：待追加的字节数。
// 返回值：目标字符串dest的地址。
char *STRNCAT(char* dest,const size_t destlen,const char* src, const size_t n);


// 将可变参数(...)按照fmt描述的格式输出到dest字符串中。
// dest：输出字符串，不需要初始化，在SPRINTF函数中会对它进行初始化。
// destlen：输出字符串dest占用内存的大小，如果格式化后的字符串长度大于destlen-1，后面的内容将丢弃。
// fmt：格式控制描述。
// ...：填充到格式控制描述fmt中的参数。
// 返回值：格式化后的字符串的长度，程序员一般不关心返回值。
int SPRINTF(char *dest,const size_t destlen,const char *fmt,...);


// 重置文件的修改时间属性。
// filename：待重置的文件名，建议采用绝对路径的文件名。
// stime：字符串表示的时间，格式不限，但一定要包括yyyymmddhh24miss，一个都不能少，顺序也不能变。
// 返回值：true-成功；false-失败，失败的原因保存在errno中。
bool UTime(const char *filename,const char *mtime);


// 把字符串表示的时间转换为整数表示的时间。
// stime：字符串表示的时间，格式不限，但一定要包括yyyymmddhh24miss，一个都不能少，顺序也不能变。
// 返回值：整数表示的时间，如果stime的格式不正确，返回-1。
time_t strtotime(const char *stime);


// 从一个字符串中提取出数字、符号和小数点，存放到另一个字符串中。
// src：原字符串。
// dest：目标字符串。
// bsigned：是否包括符号（+和-），true-包括；false-不包括。
// bdot：是否包括小数点的圆点符号，true-包括；false-不包括。
void PickNumber(const char *src,char *dest,const bool bsigned,const bool bdot);


// 获取文件的大小。
// filename：待获取的文件名，建议采用绝对路径的文件名。
// 返回值：如果文件不存在或没有访问权限，返回-1，成功返回文件的大小，单位是字节。
int FileSize(const char *filename);


// 把字符串表示的时间加上一个偏移的秒数后得到一个新的字符串表示的时间。
// in_stime：输入的字符串格式的时间，格式不限，但一定要包括yyyymmddhh24miss，一个都不能少，顺序也不能变。
// out_stime：输出的字符串格式的时间。
// timetvl：需要偏移的秒数，正数往后偏移，负数往前偏移。
// fmt：输出字符串时间out_stime的格式，与LocalTime函数的fmt参数相同。
// 注意：in_stime和out_stime参数可以是同一个变量的地址，如果调用失败，out_stime的内容会清空。
// 返回值：true-成功，false-失败，如果返回失败，可以认为是in_stime的格式不正确。
bool AddTime(const char *in_stime,char *out_stime,const int timetvl,const char *fmt=0);


// 解析xml格式字符串的函数族。
// xml格式的字符串的内容如下：
// <filename>/tmp/freecplus.h</filename><mtime>2020-01-01 12:20:35</mtime><size>18348</size>
// <filename>/tmp/freecplus.cpp</filename><mtime>2020-01-01 10:10:15</mtime><size>50945</size>
// xmlbuffer：待解析的xml格式字符串。
// fieldname：字段的标签名。
// value：传入变量的地址，用于存放字段内容，支持bool、int、insigned int、long、unsigned long、double和char[]。
// 注意，当value参数的数据类型为char []时，必须保证value数组的内存足够，否则可能发生内存溢出的问题>，也可以用ilen参数限定获取字段内容的长度，ilen的缺省值为0，表示不限长度。
// 返回值：true-成功；如果fieldname参数指定的标答名不存在，返回失败。
bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,bool *value);
bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,int  *value);
bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,unsigned int *value);
bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,long *value);
bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,unsigned long *value);
bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,double *value);
bool GetXMLBuffer(const char *xmlbuffer,const char *fieldname,char *value,const int ilen=0);


/////////////////* $End FUNCTION *///////////////


/////////////////* $Begin CLASS *////////////////


// 计时器
class CTimer
{
private:
    struct timeval m_start;
    struct timeval m_end;
    void Start();

public:
    CTimer(); // 构造函数会调用Start() 

    // 计算逝去的时间,单位: 秒, 小数点后面为微秒
    double Elapsed(); 

};


// 文件操作类声明
class CFile
{
private:
    FILE *m_fp;                // 文件指针
    bool  m_bEnBuffer;         // 是否启用缓冲，true-启用；false-不启用，缺省是启用。
    char  m_filename[301];     // 文件名，建议采用绝对路径的文件名。
    char  m_filenametmp[301];  // 临时文件名，在m_filename后加".tmp"。
 
public:
    CFile();   // 类的构造函数。
   ~CFile();   // 类的析构函数。
 
    bool IsOpened();  // 判断文件是否已打开，返回值：true-已打开；false-未打开。
 
    // 打开文件。
    // filename：待打开的文件名，建议采用绝对路径的文件名。
    // openmode：打开文件的模式，与fopen库函数的打开模式相同。
    // bEnBuffer：是否启用缓冲，true-启用；false-不启用，缺省是启用。
    // 注意：如果待打开的文件的目录不存在，就会创建目录。
    bool Open(const char *filename,const char *openmode,bool bEnBuffer=true);
 
    // 关闭文件指针，并删除文件。
    bool CloseAndRemove();
 
    // 专为重命名而打开文件，参数与Open方法相同。
    // 注意：OpenForRename打开的是filename后加".tmp"的临时文件，所以openmode只能是"a"、"a+"、"w"、"w+"。
    bool OpenForRename(const char *filename,const char *openmode,bool bEnBuffer=true);
    // 关闭文件指针，并把OpenForRename方法打开的临时文件名重命名为filename。
    bool CloseAndRename();
 
    // 调用fprintf向文件写入数据，参数与fprintf库函数相同，但不需要传入文件指针。
    void Fprintf(const char *fmt,...);
 
    // 从文件中读取以换行符"\n"结束的一行。
    // buffer：用于存放读取的内容。
    // readsize：本次打算读取的字节数，如果已经读取到了结束标志"\n"，函数返回。
    // bdelcrt：是否删除行结束标志，true-删除；false-不删除，缺省值是false。
    // 返回值：true-成功；false-失败，一般情况下，失败可以认为是文件已结束。
    bool Fgets(char *buffer,const int readsize,bool bdelcrt=false);
 
    // 从文件文件中读取一行。
    // buffer：用于存放读取的内容。
    // readsize：本次打算读取的字节数，如果已经读取到了结束标志，函数返回。
    // endbz：行内容结束的标志，缺省为空，表示行内容以"\n"为结束标志。
    // 返回值：true-成功；false-失败，一般情况下，失败可以认为是文件已结束。
    bool FFGETS(char *buffer,const int readsize,const char *endbz=0);
 
    // 从文件中读取数据块。
    // ptr：用于存放读取的内容。
    // size：本次打算读取的字节数。
    // 返回值：本次从文件中成功读取的字节数，如果文件未结束，返回值等于size，如果文件已结束，返回值为实际读取的字节数。
    size_t Fread(void *ptr,size_t size);
 
    // 向文件中写入数据块。
    // ptr：待写入数据的地址。
    // size：待写入数据的字节数。
    // 返回值：本次成功写入的字节数，如果磁盘空间足够，返回值等于size。
    size_t Fwrite(const void *ptr,size_t size);
 
    // 关闭文件指针，如果存在临时文件，就删除它。
    void Close();
};


// CCmdStr类用于拆分有分隔符的字符串。
// 字符串的格式为：字段内容1+分隔符+字段内容2+分隔符+字段内容3+分隔符+...+字段内容n。
// 例如："messi,10,striker,30,1.72,68.5,Barcelona"，这是足球运动员梅西的资料，包括姓名、
// 球衣号码、场上位置、年龄、身高、体重和效力的俱乐部，字段之间用半角的逗号分隔。
class CCmdStr
{
public:
    vector<string> m_vCmdStr;  // 存放拆分后的字段内容。

    CCmdStr();  // 构造函数。

    // 把字符串拆分到m_vCmdStr容器中。
    // buffer：待拆分的字符串。
    // sepstr：buffer中采用的分隔符，注意，sepstr参数的数据类型不是字符，是字符串，如","、" "、"|"、"~!~"。
    // bdelspace：拆分后是否删除字段内容前后的空格，true-删除；false-不删除，缺省删除。
    void SplitToCmd(const string buffer,const char *sepstr,const bool bdelspace=true);

    // 获取拆分后字段的个数，即m_vCmdStr容器的大小。
    int CmdCount();

    // 从m_vCmdStr容器获取字段内容。
    // inum：字段的顺序号，类似数组的下标，从0开始。
    // value：传入变量的地址，用于存放字段内容。
    // 返回值：true-成功；如果inum的取值超出了m_vCmdStr容器的大小，返回失败。
    bool GetValue(const int inum,char *value,const int ilen=0); // 字符串，ilen缺省值为0。
    bool GetValue(const int inum,int    *value); // int整数。
    bool GetValue(const int inum,unsigned int *value); // unsigned int整数。
    bool GetValue(const int inum,long *value); // long整数。
    bool GetValue(const int inum,unsigned long *value); // unsigned long整数。
    bool GetValue(const int inum,double *value); // 双精度double。
    bool GetValue(const int inum,bool *value); // bool型。

    ~CCmdStr(); // 析构函数。
};


// 日志文件操作类
class CLogFile
{
public:
    FILE   *m_tracefp;           // 日志文件指针。
    char    m_filename[301];     // 日志文件名，建议采用绝对路径。
    char    m_openmode[11];      // 日志文件的打开方式，一般采用"a+"。
    bool    m_bEnBuffer;         // 写入日志时，是否启用操作系统的缓冲机制，缺省不启用。
    long    m_MaxLogSize;        // 最大日志文件的大小，单位M，缺省100M。
    bool    m_bBackup;           // 是否自动切换，日志文件大小超过m_MaxLogSize将自动切换，缺省启用。

  // 构造函数。
  // MaxLogSize：最大日志文件的大小，单位M，缺省100M，最小为10M。
  CLogFile(const long MaxLogSize=100);

  // 打开日志文件。
  // filename：日志文件名，建议采用绝对路径，如果文件名中的目录不存在，就先创建目录。
  // openmode：日志文件的打开方式，与fopen库函数打开文件的方式相同，缺省值是"a+"。
  // bBackup：是否自动切换，true-切换，false-不切换，在多进程的服务程序中，如果多个进程共用一个日志文件，bBackup必须为false。
  // bEnBuffer：是否启用文件缓冲机制，true-启用，false-不启用，如果启用缓冲区，那么写进日志文件中的内容不会立即写入文件，缺省是不启用。
    bool Open(const char *filename,const char *openmode=0,bool bBackup=true,bool bEnBuffer=false);

  // 如果日志文件大于m_MaxLogSize的值，就把当前的日志文件名改为历史日志文件名，再创建新的当前日志文件。
  // 备份后的文件会在日志文件名后加上日期时间，如/tmp/log/filetodb.log.20200101123025。
  // 注意，在多进程的程序中，日志文件不可切换，多线的程序中，日志文件可以切换。
    bool BackupLogFile();

  // 把内容写入日志文件，fmt是可变参数，使用方法与printf库函数相同。
  // Write方法会写入当前的时间，WriteEx方法不写时间。
    bool Write(const char *fmt,...);
    bool WriteEx(const char *fmt,...);

  // 关闭日志文件
    void Close();

    ~CLogFile();  // 析构函数会调用Close方法。
};



/////////////////* $End CLASS *//////////////////


#endif
/* $End shark.h */
