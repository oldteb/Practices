#define   NULL    0


//Definition for binary tree
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




    
    bool vbst(TreeNode *pnode, TreeNode *pn1, TreeNode *pn2){
    	
    	if(pnode == NULL){
    		return true;
    	}
    	
    	if(pn1 != NULL){
    		if(pnode->val <= pn1->val){
    			return false;
    		}
    	}
    	
    	if(pn2 != NULL){
    		if(pnode->val >= pn2->val){
    			return false;
    		}
    	}
    	
    	if(vbst(pnode->left,pn1,pnode)){
    		return vbst(pnode->right,pnode,pn2);
    	}
    	
    	return false;
	
    }
    
    
    bool isValidBST(TreeNode *root) {
        if(root == NULL){
        	return true;
        }
        
		if(vbst(root->left,NULL,root)){
			return vbst(root->right,root,NULL);
		}
		
		return false;
    }

