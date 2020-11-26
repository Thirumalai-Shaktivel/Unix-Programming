#include <stdio.h>
#include<sys/stat.h>
int main()
{
    //umask(0000);
    mkfifo("FIFO5", 0777);
}
