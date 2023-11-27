#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

char *
fmtname(char *path)
{
    char *p;
    static char buf[DIRSIZ+1];
    for( p= path + strlen(path); *p != '/' && p >= path;p--)
    p++;
    if (strlen(p)>=DIRSIZ)
        return p;
    memmove(buf,p,strlen(p));
    memset(buf+strlen(p),' ',DIRSIZ-strlen(p));
    return buf;
}

void find(char *Path,char *FileName)
{
    int fd;
    // struct dirent de;
    struct stat st;
    printf("Current Path is %s",Path);
    if( (fd = open(Path,0))<0)
    {
        fprintf(2,"cannt open path file");
        return;
    }

    if( fstat(fd,&st)<0)
    {
        fprintf(2,"ls cant open stat");
        return;
    }

    switch(st.type)
    {
        case T_DEVICE:
        case T_FILE:
        if(strcmp(fmtname(Path),FileName))
        {
            printf("Find File");
            exit(0);
        }
        break;       
        case T_DIR:

            
            
    }    

}



int main(int argc, char * argv[])
{
    // int i;
    if (argc != 3)
    {
        fprintf(2,"error with input paramater");
        
    }
    else
    {
        find(argv[1],argv[2]);

    }
    exit(0);

}