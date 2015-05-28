#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char a[50],z;
    int i,n,b;
    printf("Please input a short sentence:\n");
    gets(a);                       /*用gets()函数输入时，可以输入句子（中间带空格）而printf()语句把空格符视为字符串分隔符。*/ 
    for(n=0,i=strlen(a)-1;n<i;n++,i--)
    {
        z=a[n];a[n]=a[i];a[i]=z;
    }
    printf("%s",a);
    system("PAUSE");
    
    return 0;
}
        
        
        
