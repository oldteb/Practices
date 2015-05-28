#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
#include<errno.h>
#include<signal.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<fcntl.h>


#define      TRUE            1
#define      FALSE           0
#define      BUF_SIZE        20
#define      MAX_PARA        6
#define      HASH(i)         strlen(parameter[i])%5
#define      DEFAULT_FILE    "SHTTPD-defaultfile.txt"
#define      BUFFER_SIZE     400

#define  PAGE_BUF_SIZE      1024*64
#define  SERVPORT      8080
#define  MAX_CLN       8
#define  MAX_MSGID     10
#define  BASE_CLIENT   2


typedef enum {number,string} ElemTag;
char* parameter[BUF_SIZE]={"-ListenPort","-MaxClient","-TimeOut","-DocunmentRoot","-CGIRoot","-DefaultFile","-ConfigFile"};
ElemTag parameterType[BUF_SIZE]={number,number,number,string,string,string,string};
int   di[MAX_PARA] = {8,80,0,5};
char* ds[MAX_PARA] = {"","","index.htm","/home/www/cgi-bin/","/home/www/"};
int  isConfUsed = FALSE;



typedef struct Node
{
    char* cp;
    ElemTag tag;
    union{
        int num;
        char buf[BUF_SIZE];
    };
    struct Node* next;
}Node,*pNode;

typedef struct hNode
{
    int num;
    pNode head;
    pNode cur;
}hNode;


typedef struct fNode
{
    ElemTag tag;
    int modify;
    union{
        int num;
        char* buf;
    };        
}fNode;

struct msgbuf{
    long mtype;
    char mtext[1];
}msgbuf;


static fNode fi[MAX_PARA];
static fNode fs[MAX_PARA];
//函数定义-----------------------------------------------
int match_L(char* buffer,int* i)
{
    int j=0;
    char buf[BUF_SIZE]={0};
    *i = (*i)+10;
    while((*(buffer+(*i)))!='=')
    {
        (*i)++;
        continue;                          
    }            
    *i=(*i)+2;
    while(*(buffer+(*i))!='\r')
    {
        buf[j] = *(buffer+(*i));
        (*i)++;
        j++;                                                     
    }      
    (*i) = (*i)+2;  
    fi[1].num = atoi(buf);
    fi[1].modify = 1;
    fi[1].tag = number;     
    return 0;              
}

int match_M(char* buffer,int* i)
{
    int j=0;
    char buf[BUF_SIZE]={0};
    *i = (*i)+9;
    while(*(buffer+(*i))!='=')
    {
        (*i)++;
        continue;                          
    }            
    *i=(*i)+2;
    while(*(buffer+(*i))!='\r')
    {
        buf[j] = *(buffer+(*i));
        (*i)++;
        j++;                                                     
    }       
    (*i) = (*i)+2;    
    fi[0].num = atoi(buf);
    fi[0].modify = 1;
    fi[0].tag = number;      
    return 0;  
}

int match_Do(char* buffer,int* i)
{
    int j=0;
    char* buf = (char*)malloc(BUF_SIZE*sizeof(char));
    *i = (*i)+13;
    while(*(buffer+(*i))!='=')
    {
        (*i)++;
        continue;                          
    }            
    *i=(*i)+2;
    while(*(buffer+(*i))!='\r')
    {
        buf[j] = *(buffer+(*i));
        (*i)++;
        j++;                                                     
    }
    buf[j] = '\0';       
    (*i) = (*i)+2;    
    fs[4].buf = buf;
    fs[4].modify = 1;
    fs[4].tag = string;      
    return 0;                             
}

int match_De(char* buffer,int* i)
{
    int j=0;
    char* buf = (char*)malloc(BUF_SIZE*sizeof(char));
    *i = (*i)+11;
    while(*(buffer+(*i))!='=')
    {
        (*i)++;
        continue;                          
    }            
    *i=(*i)+2;
    while(*(buffer+(*i))!='\r')
    {
        buf[j] = *(buffer+(*i));
        (*i)++;
        j++;                                                     
    }
    buf[j] = '\0';       
    (*i) = (*i)+2;    
    fs[2].buf = buf;
    fs[2].modify = 1;
    fs[2].tag = string;     
    return 0;                             
}

int match_C(char* buffer,int* i)
{
    int j=0;
    char* buf = (char*)malloc(BUF_SIZE*sizeof(char));
    *i = (*i)+7;
    while(*(buffer+(*i))!='=')
    {
        (*i)++;
        continue;                          
    }            
    *i=(*i)+2;
    while(*(buffer+(*i))!='\r')
    {
        buf[j] = *(buffer+(*i));
        (*i)++;
        j++;                                                     
    }
    buf[j] = '\0';       
    (*i) = (*i)+2;    
    fs[3].buf = buf;
    fs[3].modify = 1;
    fs[3].tag = string;   
    return 0;                             
}

int match_T(char* buffer,int* i)
{
    int j=0;
    char buf[BUF_SIZE]={0};
    *i = (*i)+7;
    while(*(buffer+(*i))!='=')
    {
        (*i)++;
        continue;                          
    }            
    *i=(*i)+2;
    while(*(buffer+(*i))!='\r')
    {
        buf[j] = *(buffer+(*i));
        (*i)++;
        j++;                                                     
    }       
    (*i) = (*i)+2;   
    fi[3].num = atoi(buf);
    fi[3].modify = 1;
    fi[3].tag = number;  
    return 0;  
}





int readFromConf(char* ccp)
{
    int i=0;
    char* buffer;
    int fsize;
    int result;
    FILE* fp = fopen(ccp,"r");
    
    /* 获取文件大小 */  
    fseek (fp , 0 , SEEK_END);  
    fsize = ftell(fp);  
    rewind (fp);  
  
    /* 分配内存存储整个文件 */   
    buffer = (char*) malloc (fsize*sizeof(char));  
    if (buffer == NULL)  
    {  
        fputs ("Memory error",stderr); 
        //system("pause");
        exit (2);  
    }  

    /* 将文件拷贝到buffer中 */  
    result = fread (buffer,1,fsize,fp);  
    
    //printf("%s\n\n",buffer);
    while(i<result)
    {  
        if(*(buffer+i)=='#')
        {
            while(*(buffer+i)!='\n')
            { 
                i++;
                continue;                   
            } 
            i++;
            continue;                  
        }    
        switch(*(buffer+i))
        {
            case 76:  match_L(buffer,&i);  break;
            case 77:  match_M(buffer,&i);  break; 
            case 68:  i++;   
                      if((*(buffer+i))==111) {
                          match_Do(buffer,&i);
                      }
                      else 
                          match_De(buffer,&i);
                      break;
            case 67:  match_C(buffer,&i);  break;  
            case 84:  match_T(buffer,&i);  break;               
            default:  break;                   
        }                  
    }
    return 0;
    
}



int BuildHash(hNode* list)
{
    int i;
    pNode pn;
    for(i=0;i<MAX_PARA;i++)
    {
        list[i].num = 0;
        list[i].head = NULL;
    }
    
    for(i=0;i<7;i++)
    {
        pn = (pNode)malloc(sizeof(Node));
        pn->cp = parameter[i];
        pn->tag = parameterType[i];
        pn->next = NULL;
        if(list[HASH(i)].num==0)
        {
            list[HASH(i)].head = pn;  
            list[HASH(i)].cur = pn;
            list[HASH(i)].num++;
        } 
        else
        {
            list[HASH(i)].cur->next = pn; 
            list[HASH(i)].cur = pn;  
            list[HASH(i)].num++;     
        }                    
    }
    
    return 0;
}

int hash(char* tar,hNode* list)
{  
    for(list[strlen(tar)%5].cur=list[strlen(tar)%5].head;list[strlen(tar)%5].cur!=NULL;list[strlen(tar)%5].cur=list[strlen(tar)%5].cur->next)
    {                                                                                                                             
        if(strcmp(list[strlen(tar)%5].cur->cp,tar)==0)
            return strlen(tar)%5;                    
        else
            continue;                               
    }
    printf("Unknown parameter:%s\n",tar);
    exit(0); 
}

ElemTag type(char* tar,hNode* list)
{
    for(list[strlen(tar)%5].cur=list[strlen(tar)%5].head;list[strlen(tar)%5].cur!=NULL;list[strlen(tar)%5].cur=list[strlen(tar)%5].cur->next)
    {
        if(strcmp(list[strlen(tar)%5].cur->cp,tar)==0)
            return list[strlen(tar)%5].cur->tag;                     
        else
            continue;                               
    }
    printf("Unknown type:%s\n",tar);
    exit(0); 
}



int printUsage()
{
    printf("Arguement ERROR!\nThe usage:SHTTPD [-ListenPort number] [-MaxClient number] [-DocunmentRoot path] [-CGIRoot path] [-DefaultFile filename] [-TimeOut seconds] [-ConfigFile filename]\n");
    return 0;
}


int param_analyse(int argc,char* argv[],hNode* list)
{
    int i,j;
    if(argc>14)  
    {
        printUsage();
        return 0;
    }
    BuildHash(list);
    readFromConf(DEFAULT_FILE);
    
    //printf("-------------%s\n",fs[4].buf);
    
    
    
    for(i=1;i<=argc-1;i=i+2)
    {

        if(strcmp("-ConfigFile",argv[i])==0)
        {
            isConfUsed = TRUE;
            continue;
        }
        j = hash(argv[i],list);
        if(type(argv[i],list)==number)
        {
            fi[j].num = atoi(argv[i+1]);
            fi[j].modify = 2; 
        }
        else 
        {
            fs[j].buf = argv[i+1];
            fs[j].modify = 2; 
        }          
    }
    
    for(i=0;i<=MAX_PARA;i++)
    {                       
        if(isConfUsed==TRUE && fi[i].tag==number)
            di[i] = fi[i].num; 
        else if(isConfUsed==FALSE && fi[i].modify==2)
            di[i] = fi[i].num;  
    }
    for(i=0;i<=MAX_PARA;i++)
    {                       
        if(isConfUsed==TRUE && fs[i].tag==string)
            ds[i] = fs[i].buf; 
        else if(isConfUsed==FALSE && fs[i].modify==2)
            ds[i] = fs[i].buf;
    }      
    
    //getchar();
    return 0;
} 

int deal(char* buffer,int clientfd)
{
    int nSize = 0;
    char *pPos;
    FILE* fd;
    char ch[100];
    char dir[100];
    
    pPos = strstr(buffer,"GET");
    if(pPos == NULL)
    {
        memset(buffer,0,sizeof(buffer));
        strcpy(buffer,"wrong request!\n");
        nSize = 16;
        write(clientfd,buffer,nSize);
        printf("wrong request..\n");
        exit(0);   
    }
    if((int)(pPos-buffer)!=0)
    {
        memset(buffer,0,sizeof(buffer));
        strcpy(buffer,"ERROR 490");
        nSize = 10;
	write(clientfd,buffer,nSize);               
    }
    else
    {
        strncpy(ch,(char*)(buffer+4),100);
        pPos = strstr(ch," ");
	if((int)(pPos-ch)==1)
        {
	    memset(ch,0,100);
	    strcpy(ch,"/index.htm");
	}
	else
	{	
  	    *(pPos) = '\0';
  	}
        strcpy(dir,ds[4]);
        strcat(dir,ch);
        printf("%s\n",dir);
        fd = fopen(dir,"r");
	printf("-->%d\n",(int)fd);
        if((int)fd == 0)
        {
            memset(buffer,0,PAGE_BUF_SIZE);
            strcpy(buffer,"ERROR 491");
            nSize = 10;
            write(clientfd,buffer,nSize);  
        }
        else
        { 
            memset(buffer,0,PAGE_BUF_SIZE);
            while((nSize = fread (buffer,sizeof(char),PAGE_BUF_SIZE,fd))>0)
            {
                write(clientfd,buffer,nSize);
                memset(buffer,0,PAGE_BUF_SIZE);                
            }
            fclose(fd);
        }
    }
    return 0;
}

int main(int argc,char* argv[])
{
    hNode list[MAX_PARA];
    int test;
    int i;
    char c;
    int on;
    int sockfd,clientfd;
    int sin_size;
    int nbytes;
    int pid;
    int pid_arr[MAX_CLN] = {0};
    int msgID[MAX_MSGID] = {0};
    char buffer[PAGE_BUF_SIZE] = {0};
    struct sockaddr_in my_addr;
    struct sockaddr_in remote_addr;
    
    int flags;
    struct msgbuf msgT = {0};
    int msgLength = sizeof(struct msgbuf)-sizeof(long);
    
    
    if(argc>1) 
        param_analyse(argc,argv,list);  
    
    printf("ListenPort=%d\nMaxClient=%d\nTimeOut=%d\n",di[1],di[0],di[3]);
    printf("DocunmentRoot=%s\nCGIRoot=%s\nDefaultFile=%s\n",ds[4],ds[3],ds[2]);
    
    //开始通信。。。 
    msgT.mtype = 1;
    msgT.mtext[0]=0;
       
    //socket(), bind(), listen()... 
    if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        perror("socket creat error!\n");
        exit(0);            
    }
    
    //设置此socket 允许地址重用... 
    on = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on) );
    
    
    //set sockfd to non-blocking...
    flags = fcntl(sockfd,F_GETFL,0);
    fcntl(sockfd,F_SETFL,flags|O_NONBLOCK);
    
    
    
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(di[1]);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(my_addr.sin_zero),8);
    if(bind(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))==-1)
    {
        perror("bind error!\n");
        exit(1);                                  
    }
    
    if(listen(sockfd,di[0])==-1)
    {
        perror("listen error!\n");
        exit(0);                                                         
    }
    printf("ready to accept...\n");
    
    
    for(i=1;i<=BASE_CLIENT;i++)
        msgID[i] = msgget(IPC_PRIVATE,IPC_CREAT|0660);
    //预创建 BASE_CLIENT 个子处理进程... 
    for(i=1;i<=BASE_CLIENT;i++)
    {      
        pid_arr[0] = i;
        pid = fork();          
        if(pid==0)
        {
            printf("subprocess(%d) is creating...\n",pid_arr[0]);
            while(1)
            {        
                test = msgrcv(msgID[pid_arr[0]],(void *)&msgT,msgLength,1,IPC_NOWAIT);
                //printf("%d:%c\n",pid_arr[0],msgT.mtext[0]);
                if(msgT.mtext[0]=='E')
                {
                    printf("subprocess(%d) is closing...\n",pid_arr[0]);
                    exit(0);
                }
                else if(errno == EAGAIN || errno == ENOMSG)
                {
                    if((clientfd = accept(sockfd,(struct sockaddr*)&remote_addr,&sin_size))==-1)
                    {
                        sleep(1);
                        continue;               
                    }   
                    /*if(send(clientfd,"Hello, you are connected!\n",26,0)==-1)
                    {
                        perror("send error!\n");
                        exit(0);                         
                    }  
                    */    
                    printf("\nreceived a connection from %s\nprocess(%d) is dealing...\nwaiting for request...\n",(char *)inet_ntoa(remote_addr.sin_addr),pid_arr[0]);  
                    if((nbytes = read(clientfd,buffer,1024))==-1)
                    {
                        printf("read error:%s\n",strerror(errno));
                        exit(0);           
                    }
                    buffer[nbytes] = '\0';
                    printf("%s\n",buffer);
                    deal(buffer,clientfd);
                    close(clientfd);
                }
                else
                {
                    printf("%s\n",strerror(errno));
                    printf("Unexpected error at msgrcv\n");
                    printf("subprocess(%d) is closing...\n",pid_arr[0]);
                    exit(0);    
                }  
                sleep(1);
            }                
        }
        else 
        {
            pid_arr[i] = pid;
        }                      
    }
    printf("main\n");
    
    
    //send_close()...
    printf("command waiting...\n");
    while((c = getchar())!='E');
    msgT.mtext[0] = 'E';
    for(i=1;i<=pid_arr[0];i++)
        if(msgsnd(msgID[i],&msgT,msgLength,0)==0)
            printf("success\n");                                 
            
            
    while(wait(NULL)!=-1 || errno!=ECHILD);
    printf("All the subprocess have exited successfully\n");
    close(sockfd);
    return 0;
}



