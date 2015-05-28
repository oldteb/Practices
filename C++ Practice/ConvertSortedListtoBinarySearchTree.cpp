#include<stdio.h>
#include<stdlib.h>

//Definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Definition for binary tree
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

  
    TreeNode *help(int head, int tail, ListNode **next){
    	if(head == tail){
    		TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    		root->val = (*next)->val;
    		root->left = NULL;
    		root->right = NULL;
    		*next = (*next)->next;
    		return root;
    	}
    	int mid = (tail+head)/2;
    	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    	//root->val = buf[mid];
    	if(mid-1 >= head){
    		root->left = help(head, mid-1,next);
    	}
    	else
    		root->left = NULL;
    		
    	root->val = (*next)->val;
    	*next = (*next)->next;

    	if(mid+1 <= tail){
    		root->right = help(mid+1, tail,next);
    	}
    	else
    		root->right = NULL;
		
		return root;
    }  
  
    TreeNode *sortedListToBST(ListNode *head) {
        //int buf[100000] = {};
        int i = 0;
        if(head == NULL){
        	return NULL;
        }
        ListNode *temp = head;
        while(temp != NULL){
        	//buf[i] = temp->val;
        	i++;
        	temp = temp->next;
        }
        TreeNode * root = help(0,i-1,&head);
        
        return root;
    }
    

    
    int main(){
    	ListNode *ln1 = (ListNode *)malloc(sizeof(ListNode));
    	ListNode *ln2 = (ListNode *)malloc(sizeof(ListNode));
    	ListNode *ln3 = (ListNode *)malloc(sizeof(ListNode));
    	ListNode *ln4 = (ListNode *)malloc(sizeof(ListNode));
    	ln1->val = -1;
    	ln2->val = 0;
    	ln3->val = 1;
    	ln4->val = 2;
    	ln1->next = ln2;
    	ln2->next = ln3;
    	ln3->next = ln4;
    	ln4->next = NULL;
    	TreeNode *root = sortedListToBST(ln1);
    	
    	printf("%d %d\n",root->val,root->right->val);
    	
    	return 0;
    }


