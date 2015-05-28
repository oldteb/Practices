#include<stdio.h>
#include<stdlib.h>

// 2 to 1
int singleNumber1(int A[], int n) {
	int result = 0x0;
     for(int i = 0; i < n; i++){
     	result = A[i] ^ result;
     }
	 
	 return result;   
}

// 3 to 1
int singleNumber2(int A[], int n) {
	int d = 0;
	int c = 0 ;
	int result = 0;
	
	for(int i = 0; i < 32; i++){
		d = 1<<i; c = 0;
		for(int j = 0; j < n; j++){
			if(A[j] & d){
				c++;
			}
		}
		
		if(c%3){
			result |= d;
		}
	}
	 
	 return result;   
}


int main(){
	
	
	
	
}




