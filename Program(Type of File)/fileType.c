#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat temp;
    char *ptr;
    for (int i = 1; i < argc; i++) {
        printf(" '%s' : ", argv[i]);
        if (lstat(argv[i], &temp) < 0) {
            printf("No Such file or Enter the proper File name!!\n");
            continue;
        }
        int buf = temp.st_mode;
        if (S_ISREG(buf))
            ptr = "Regular File";
        else if (S_ISDIR(buf))
            ptr = "Directory File";
        else if (S_ISCHR(buf))
            ptr = "Character special File";
        else if (S_ISBLK(buf))
            ptr = "Block special File";
        else if (S_ISFIFO(buf))
            ptr = "FIFO or pipe";
        else if (S_ISLNK(buf))
            ptr = "Symbolic link";
        else if (S_ISSOCK(buf))
            ptr = "Socket";
        else
            ptr = "Not sure, Which mode is that!!";
        printf("%s\n", ptr);
    }
    return 0;
}
