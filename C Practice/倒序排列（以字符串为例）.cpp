#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char a[50],z;
    int i,n,b;
    printf("Please input a short sentence:\n");
    gets(a);                       /*��gets()��������ʱ������������ӣ��м���ո񣩶�printf()���ѿո����Ϊ�ַ����ָ�����*/ 
    for(n=0,i=strlen(a)-1;n<i;n++,i--)
    {
        z=a[n];a[n]=a[i];a[i]=z;
    }
    printf("%s",a);
    system("PAUSE");
    
    return 0;
}
        
        
        
