     #include<stdio.h>
     #include<stdlib.h>
    
    
	 int newrighthead(int A[], int n, int elem){
    	int temp = n-1;
    	while(temp >= 0){
    		if(A[temp] == elem){
    			temp--;
    			continue;
			}
			break;
    	}
    	return temp;
    }
    int removeElement(int A[], int n, int elem) {
    	int lefthead = 0;
        int righthead = 0;
        int temp = 0;
        
        righthead = newrighthead(A, n, elem);
        printf("%d\n",righthead);
        if(righthead == -1){
        	return 0;
        }
        
        
        for(; lefthead < n; lefthead ++){
        	printf("%d,%d\n",lefthead,righthead);
        	if(lefthead >= righthead){
        		return righthead+1;
        	}
        	if(A[lefthead] != elem){
        		continue;
        	}
        	
        	// swap
        	temp = A[lefthead];
        	A[lefthead] = A[righthead];
        	A[righthead] = temp;
        	
        	righthead = newrighthead(A, n, elem);	
        }
        
        return righthead+1;;
    }
    

    
    int main(){
    	int A[10] = {1,2,3,2};
    	int len = removeElement(A, 4, 2);
    	int i = 0;
		for(;i<len;i++){
    		printf("%d ",A[i]);
    	}
    	
    	return 0;
    	
    }

