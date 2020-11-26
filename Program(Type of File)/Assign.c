#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat temp;
    char *ptr;
    int i = 0;
    
    
    if(argc > 1){
        while(++i < argc)
        {
            printf(" File \'%s\' : >> ", argv[i]);
            
            if (lstat(argv[i], &temp) < 0) {
                printf("No Such file or Enter the proper File name!!\n");
                continue;
            }
            
            int buf = temp.st_mode;
            //printf("%d",buf);
            
            //Socket
            if(S_ISREG(buf) || S_ISDIR(buf))
            {       //0          //0
                (S_ISREG(buf) > S_ISDIR(buf)) ? (printf("\tRegular File\n")) 
                                              : (printf("\tDirectory File\n"));
            }
            else if (S_ISCHR(buf) || S_ISBLK(buf))
            {
                (S_ISCHR(buf) > S_ISBLK(buf)) ? (printf("\tCharacter special File\n")) 
                                              : (printf("\tBlock special File\n"));
            }
            else if (S_ISFIFO(buf) || S_ISLNK(buf))
            {
                (S_ISFIFO(buf) > S_ISLNK(buf)) ? (printf("\t\tFIFO or pipe\n")) 
                                               : (printf("\tSymbolic link\n")) ;
            }
            else
            {       //1
                (S_ISSOCK(buf)> 0) ? printf("\t\tSocket\n") 
                                   : printf("Unable to Recognize the Mode!!\n");
            }
        }
    }
    else{
        printf("Provide Atleast one FileName to check the Type of the File\n");
    }
    return 0;
}
