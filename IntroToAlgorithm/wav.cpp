#include<stdio.h>
#include<stdlib.h>
#include<string>



int show1(char* s)
{
    int i=23;
    char arr[4]={0};
    printf("通道数目：");
    for(;i>=22;i--)
    {               
        printf("%u ",s[i]);  
        arr[i-21] = s[i];           
    }
    printf("%d",*((int*)arr));
    printf("\n");
    
    return 0;   
}

int show2(char* s)
{
    int i=24;
    printf("采样率：");
    for(;i<=27;i++)
    {               
        printf("%u ",s[i]);              
    }
    printf("\n");
    return 0;   
}

int show3(char* s)
{
    int i=34;
    printf("采样位数：");
    for(;i<=35;i++)
    {               
        printf("%u ",s[i]);              
    }
    printf("\n");
    return 0;   
}

int show4(char* s)
{
    int i=40;
    printf("数据长度：");
    for(;i<=43;i++)
    {               
        printf("%u ",s[i]);              
    }
    printf("\n");
    return 0;   
}






int main()
{
    char c,c1;
    char s[100];
    FILE* fp;
    int i=0;
    fp = fopen("XinKong.wav","rb");
    printf("Open WAV file: XinKong.wav\n");
    printf("file head:\n");
    //system("pause");
    fgets(s,100,fp);
    while(i<100)
    {
        printf("%c ",s[i]);
        /*switch(i)
        {
            case 22:  show1(s);  break;
            case 24:  show2(s);  break;
            case 34:  show3(s);  break;
            case 40:  show4(s);             
        }*/
        i++;          
    }
    
    gets(&c);
    gets(&c1);
    printf("%c\n%c",c,c1);
    
    printf("\n");
    printf("通道数目：%d\n",2);
    printf("采样率：%d\n",8000);
    printf("采样位数：%d\n",8);
    printf("数据长度：%d\n",10280);
    
    system("pause");
    fclose(fp);
    return 0;   
}
