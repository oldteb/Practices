#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    
    
    return 0;   
}



char* LCS(char left[],char right[])
{    
    
    //LCS问题就是求两个字符串最长公共子串的问题
    int lenLeft=strlen(left),lenRight=strlen(right),k;
    //获取左子串的长度,获取右子串的长度
    char*c=(char *)malloc(lenRight),*p;//注意这里要写成char型,而不是int型,否则输入整型数据时会产生错误。      //矩阵c纪录两串的匹配情况
    int start,end,len,i,j;//start表明最长公共子串的起始点，end表明最长公共子串的终止点
    end=len=0;//len表示最长公共子串的长度
    for(i=0;i<lenLeft;i++)//串1从前向后比较
    {
        for(j=lenRight-1;j>=0;j--)//串2从后向前比较
        {    
            if(left[i] == right[j])//元素相等时
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
    p =(char*)malloc(len+1);//数组p纪录最长公共子串
    for(i=start; i<=end;i++)
    {    
        p[i-start] = right[i];
    }
    p[len]='\0';
    return p;
}
