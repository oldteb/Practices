class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int last = 0;
        int curr = 0;
		int curr_val = 0;
		        
        while(curr < n){
        	if(curr == 0){
        		curr_val = A[curr];
        		curr++;
        		continue;
        	}
        	
        	if(A[curr] == curr_val){
        		curr++;
        		continue;
        	}
        	
        	A[++last] = A[curr];
        	curr_val = A[curr];
        }
        
        return last+1;
        
    }
};
