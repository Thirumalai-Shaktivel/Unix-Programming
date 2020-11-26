#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat temp;
    char *ptr;
    int i = 0;
    
    while(++i < argc)
    {
        printf(" File \'%s\' : >> ", argv[i]);
        
        if (lstat(argv[i], &temp) < 0) {
            printf("No Such file or Enter the proper File name!!\n");
            continue;
        }
        
        int buf = temp.st_mode;
        //Regular
        
                    //true
        int i = S_ISREG(buf)   ? 1 : 0
                + S_ISDIR(buf) ? 2 : 0
                + S_ISCHR(buf) ? 3 : 0
                + S_ISBLK(buf) ? 4 : 0
                + S_ISFIFO(buf)? 5 : 0
                + S_ISLNK(buf) ? 6 : 0
                + S_ISSOCK(buf)? 7 : 0;
            
        //2
        switch(i) 
        {
            case 1:
                printf("\tRegular File\n");
                    break;
            case 2:
                printf("\tDirectory File\n");
                    break;
            case 3:
                printf("\tCharacter special File\n");
                    break;
            case 4:
                printf("\tBlock special File\n");
                    break;
            case 5:
                printf("\t\tFIFO or pipe\n");
                    break;
            case 6:
                printf("\tSymbolic link\n");
                    break;
            case 7:
                printf("\t\tSocket\n");
                    break;
            case 0:
            default:
                printf("I never Discovered that mode till now!!\n");
                    break;
        }
    }
    return 0;
}
