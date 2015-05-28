#include<iostream>
#define    OK            1       
#define    ERROR         0 
#define    ARRAYLENGTH   100  
#define    _chk           cout<<"ERROR";    

using namespace std;

typedef struct TNode{
    string word;
    int    count;
    TNode* left;
    TNode* right;
}TNode,*ptnode;

typedef struct{
    int    num;
    TNode* ptn;
}HeadTNode;

bool InputWords(string* );
bool InitTnodeTree(HeadTNode& );
bool Push(HeadTNode& ,string* );
TNode* FindP(TNode* );



int main(){
    int i;
    string words[ARRAYLENGTH];
    HeadTNode htnd;
    InitTnodeTree(htnd);
    //for(i=0;words[i]!="#";i++)
    //    cout<<words[i];
    system("pause");
    return 0;
}

bool InputWords(string words[]){
    int i;
    for(i=1;words[i-1]!="#";i++)
        cin>>words[i];  
    return OK;    
}

bool InitTnodeTree(HeadTNode& htnd){
    htnd.num=0;
    return OK;
}

bool Push(HeadTNode& htnd,string words[]){
    int i=1,d;
    TNode* p;
    InputWords(words);
    if(htnd.num==0 && words[i]!="#"){
        htnd.ptn=new TNode;
        htnd.ptn->word=words[i];
        htnd.ptn->count=i;
        htnd.num++;  i++;
    }
    for(;words[i]!="#";i++)
        FindP(htnd.ptn)=new TNode;
        

       
}

TNode* FindP(TNode* ptn){
    if(ptn->left!=NULL){
        if(ptn->right!=NULL){
            return FindP(ptn->left);
            return FindP(ptn->right);
        }
        else return ptn->right;
    }
    else return ptn->left;
}




//感悟：
//1.传递指针时还需要引用吗？指针本身在传参时就是引用吗？ 
//2.为什么cin,cout不能输入输出char*类型？ 
