#include"/root/Shark/shark.h"

int main(int argc, char **argv)
{

    struct utimbuf st;
    memset(&st, 0, sizeof(struct utimbuf));
    st.actime = strtotime("30-01-23 2324:12:00");
    st.modtime = strtotime("30-01-23 2324:12:00");
    // st.modtime = time(0);

    utime("/root/paper/test.cpp", &st);



    return 0;
}
