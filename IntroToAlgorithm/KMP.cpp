#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    
    
    return 0;   
}



char* LCS(char left[],char right[])
{    
    
    //LCS��������������ַ���������Ӵ�������
    int lenLeft=strlen(left),lenRight=strlen(right),k;
    //��ȡ���Ӵ��ĳ���,��ȡ���Ӵ��ĳ���
    char*c=(char *)malloc(lenRight),*p;//ע������Ҫд��char��,������int��,����������������ʱ���������      //����c��¼������ƥ�����
    int start,end,len,i,j;//start����������Ӵ�����ʼ�㣬end����������Ӵ�����ֹ��
    end=len=0;//len��ʾ������Ӵ��ĳ���
    for(i=0;i<lenLeft;i++)//��1��ǰ���Ƚ�
    {
        for(j=lenRight-1;j>=0;j--)//��2�Ӻ���ǰ�Ƚ�
        {    
            if(left[i] == right[j])//Ԫ�����ʱ
            { 
                if(i==0||j==0)
                    c[j]=1;
                else
                {    
                    c[j]=c[j-1]+1;
                }
            }
            else
                c[j] = 0;
            if(c[j] > len)
            {    
                len=c[j];
                end=j;
            }
        }
    }
    start=end-len+1;
    p =(char*)malloc(len+1);//����p��¼������Ӵ�
    for(i=start; i<=end;i++)
    {    
        p[i-start] = right[i];
    }
    p[len]='\0';
    return p;
}
