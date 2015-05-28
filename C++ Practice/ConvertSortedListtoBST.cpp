#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>

#define  	NULL  0

using namespace std;

//Definition for binary tree
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

  
    TreeNode *help(vector<int> &num, int head, int tail){
    	if(head == tail){
    		TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    		root->val = num[head];
    		root->left = NULL;
    		root->right = NULL;
    		return root;
    	}
    	int mid = (tail+head)/2;
    	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    	root->val = num[mid];
    	if(mid-1 >= head){
    		root->left = help(num,head, mid-1);
    	}
    	else
    		root->left = NULL;
    		
    	root->val = num[mid];

    	if(mid+1 <= tail){
    		root->right = help(num, mid+1, tail);
    	}
    	else
    		root->right = NULL;
		
		return root;
    }  
  
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.empty()){
        	return NULL;
        }
        TreeNode * root = help(num,0,num.size()-1);
        
        return root;
    }
    

    
    int main(){
    	int num[100] = {1,2,3,4,5,6,7,8,9};
    	TreeNode *root = sortedListToBST(num);
    	
    	printf("%d %d\n",root->val,root->right->val);
    	
    	return 0;
    }


