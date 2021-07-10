#include"/root/Shark/shark.h"

int main(int argc, char **argv)
{
    vector<int> v;
    v.reserve(20);

    for (int i = 1; i <= 10; ++i)
    {
        v.push_back(i);
    }
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(5);
    v.push_back(2);
    v.push_back(2);
    v.push_back(5);
    v.push_back(5);
    v.push_back(5);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(5);

    printf("=v %d=\n",  v.size());

    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        for (vector<int>::iterator p = v2.begin(); p != v2.end(); ++p)
        {
            if (*i == *p)
            {
                v.erase(i); --i;// v2.erase(p);
            }
        }
    }

    printf("=v %d=\n",  v.size());

    for (int i = 0; i < v.size(); ++i)
    {
        printf("%d\n",  v[i]);
    }

    return 0;
}
