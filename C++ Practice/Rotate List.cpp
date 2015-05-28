#include<stdio.h>
#include<stdlib.h>



#define   NULL 	0
//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};



    ListNode *rotateRight(ListNode *head, int k) {
        ListNode * cur = head;
        ListNode * tail = head;
        ListNode * temp = NULL;
        int count = 0;
        int loop = 0;
        int i = 0;
        if(head == NULL){
        	return NULL;
        }
        else if(k == 0){
        	return head;
        }
        
        count = 1;
        
        while(cur->next != NULL){
        	count++;
        	cur = cur->next;
        }
        tail = cur;
        
        loop = k%count;
        
        if(loop == 0){
        	return head;
        }
        loop = count - loop;
        
        cur = head;
        while(i < loop-1){
        	cur = cur->next;
        	i++;
        }
        
        temp = cur->next;
        cur->next = NULL;
        tail->next = head;
        
        return temp;
        
    }
    
    
    int main(){
		ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
		p1->val = 1;
		ListNode* p2 = (ListNode*)malloc(sizeof(ListNode));
		p2->val = 2;
		ListNode* p3 = (ListNode*)malloc(sizeof(ListNode));
		p3->val = 3;
		ListNode* p4 = (ListNode*)malloc(sizeof(ListNode));
		p4->val = 4;
		ListNode* p5 = (ListNode*)malloc(sizeof(ListNode));
		p5->val = 5;
		ListNode* p6 = (ListNode*)malloc(sizeof(ListNode));
		p6->val = 6;
		ListNode* p7 = (ListNode*)malloc(sizeof(ListNode));
		p7->val = 7;
		ListNode* p8 = (ListNode*)malloc(sizeof(ListNode));
		p8->val = 8;
		p1->next = p2;
		p2->next = p3;
		p3->next = p4;
		p4->next = p5;
		p5->next = p6;
		p6->next = p7;
		p7->next = p8;
		p8->next = NULL;
		
		ListNode* h = rotateRight(p7, 9);
		
		while(h != NULL){
			printf("%d,",h->val);
			h = h->next;
		}
		
		
		
		
		return 0;
		
	}

