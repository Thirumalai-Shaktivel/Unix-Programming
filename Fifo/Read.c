#include <stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include <string.h>
int main()
{
    int fd, nob;
    char c[256], filename[20], textFile[20];
    printf("\nEnter the FIFO File name:\n");
    scanf("%s",filename);
    printf("\nEnter the Filename to which you want to print the Content:\n");
    scanf("%s",textFile);
    strcat(textFile, ".txt");
    
    printf("\tReceiver Created Successfully \nWaiting for the Content...\n"); 
    fd = open(filename,O_RDONLY);
    nob = read( fd, c, sizeof(c));
    strcat(c, "\n");
    printf("\nReceived Content is: %s",c);
    if(nob != -1){
    
        FILE *fp;
        fp = fopen(textFile, "w");
        fputs(c, fp);
        fclose(fp);
    }
        //printf("%s\n",c);
    else
        perror("read Error");
    close(fd);
    return 0;
}
