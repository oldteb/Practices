#include<stdio.h>
#include<stdlib.h>

//Definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};




ListNode *reverseBetween(ListNode *head, int m, int n) {
	if( m == n){
		return head;
	}	
	int count = 0;    
	ListNode *prehead = (ListNode *)malloc(sizeof(ListNode));
	prehead->next = head;
	ListNode *temp = prehead;
	while(temp->next != NULL){
		if(count == m-1){
			break;
		}
		count++;
		temp = temp->next;
	}
	ListNode *newtail = temp->next;
	temp->next = NULL;
	ListNode *next = newtail->next->next;
	ListNode *old = newtail;
	ListNode *cur = old->next;
	count = n-m;
	while(count > 1){
		next = cur->next;
		cur->next = old;
		old = cur;
		cur = next;
		next = next->next;
		count--;
	}
	
	cur->next = old;
	temp->next = cur;
	newtail->next = next;

	return prehead->next;
}










