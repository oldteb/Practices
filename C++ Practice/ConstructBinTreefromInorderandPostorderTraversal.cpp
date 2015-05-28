#include<stdio.h>
#include<stdlib.h>

#define   NULL   0

//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder == NULL || postorder == NULL){
        	return NULL;
        }
        TreeNode * root = BTreeBuilder(inorder, postorder);
        inorder[3] = 0;
        
        return root;
    }
    
    TreeNode * BTreeBuilder(inorder, postorder){
    	TreeNode *root = NULL;
    	if(inorder != NULL){
    		
    	}

    	return NULL;
    }
    
    
    
};
