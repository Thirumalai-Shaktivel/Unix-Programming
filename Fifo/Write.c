#include <stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include <string.h>

int main()
{   
    int fd, nob;
    char c[256], filename[20];
    printf("\n>>>>>>>>>>>>> Hello Everyone!! <<<<<<<<<<<<< \n");
    printf("Enter the File name to create FIFO File:\n");
    scanf("%s",filename);
    printf("\nPlease Create the Receiver Side!!\n");
    mkfifo(filename, 0777);
    
    fd  =   open( filename ,O_WRONLY);
    printf("\n\tSuccess!! Connection Established..");
    printf("\nEnter the Content (End the Message with \"$\") :\n");
    scanf("%[^$]s",c);
    nob = write(fd, c, strlen(c));
    if(nob!=-1)
        printf("\nFile got updated!\n"); 
    else
        perror("\nwrite Error");
    close(fd);
}
