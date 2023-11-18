#include <fcntl.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int fd ,fd1;
    printf("hello\n");
    fd = open("./1.txt",O_RDONLY);
    printf("first fd is %d\n",fd);
    fd1 = open("./2.txt",O_RDONLY);
    printf("second fd is %d\n",fd1);
    
    fd = close("./1.txt");
    printf("close first fd is %d\n",fd);
    fd1 = close("./2.txt");
    printf("close second fd is %d\n",fd1);
}