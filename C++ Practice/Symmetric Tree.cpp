#define NULL 0

 //Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        int temp = NULL;
        if (root == NULL){
        	return true;
        }
		temp = symmetric_search(root, root->left, root->right);
        if(temp != -1){
        	return true;
        }
        else 
        	return false;
    }
    
    int symmetric_search(TreeNode *root, TreeNode* p1, TreeNode* p2){
    	int temp = NULL;
    	if (p1 == root && p2 == root)
    		return 1;
    	if(p1 !=NULL && p2 != NULL){
    		if(p1->val == p2->val){
    			temp = symmetric_search(root, p1->left, p2->right);
    			if(temp != 0)
    				return temp;
    			else
    				return symmetric_search(root,p1->right, p2->left);
    		}
    		else
    			return -1;
    	}
    	else if(p1 == p2){
    		return 0;
    	}
    	else
    		return -1;
    }
    

};
