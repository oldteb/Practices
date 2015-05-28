#include<stdio.h>
#include<stdlib.h>

#define  NULL	0

 //Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



    ListNode *partition(ListNode *head, int x) {
        ListNode *last = head;
        ListNode *cur = head;
        ListNode *pre_cur = NULL;
        ListNode *temp = NULL;
        ListNode *pre_head = (ListNode *)malloc(sizeof(ListNode));
        pre_head->next = head;
        last = pre_head;
        
        if(cur == NULL){
        	return head;
        }
        
        if(cur->val < x){
        	last = last->next;
        	cur = cur->next;
        	pre_cur = last;
        }
        else{
        	pre_cur = cur;
        	cur = cur->next;
        }
        
        
        
        while(cur != NULL){
        	if(cur->val >= x){
        		pre_cur = cur;
        		cur = cur->next;
        		continue;
        	}
        	
        	
        	if(last->next == cur){
        		pre_cur = cur;
        		cur = cur->next;
        		last = last->next;
        		continue;
        	}
			
			temp = cur->next;
			pre_cur->next = temp;
			cur->next = last->next;
			last->next = cur;
			last = last->next;
			
			cur= temp;
        }
        
        return pre_head->next;
        
    }
    
    
    int main(){
		ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
		p1->val = 1;
		ListNode* p2 = (ListNode*)malloc(sizeof(ListNode));
		p2->val = 4;
		ListNode* p3 = (ListNode*)malloc(sizeof(ListNode));
		p3->val = 3;
		ListNode* p4 = (ListNode*)malloc(sizeof(ListNode));
		p4->val = 2;
		ListNode* p5 = (ListNode*)malloc(sizeof(ListNode));
		p5->val = 5;
		ListNode* p6 = (ListNode*)malloc(sizeof(ListNode));
		p6->val = 2;
		ListNode* p7 = (ListNode*)malloc(sizeof(ListNode));
		p7->val = 1;
		ListNode* p8 = (ListNode*)malloc(sizeof(ListNode));
		p8->val = 1;
		p1->next = p2;
		p2->next = p3;
		p3->next = p4;
		p4->next = p5;
		p5->next = p6;
		p6->next = p7;
		p7->next = p8;
		p8->next = NULL;
		
		
		ListNode * result = partition(p1, 4);
		while(result != NULL){
			printf("%d,",result->val);
			result = result->next;
		}
		
		
		
		
		return 0;
		
	}
    

