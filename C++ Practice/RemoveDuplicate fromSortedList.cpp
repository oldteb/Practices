#include<stdio.h>
#include<stdlib.h>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


void main(){
	
	
	
	
}


ListNode *deleteDuplicates(ListNode *head) {
	ListNode *myhead = head;
	ListNode *temp = NULL;
	while(myhead->next != NULL){
		if(myhead->next->val == myhead->val){
			temp = myhead->next->next;
			myhead->next = temp;
		}
		myhead = myhead->next;
	}
	return head;	
}




