#include<stdio.h>
#include<stdlib.h>



#define   NULL 	0
//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};



	ListNode * reverse(ListNode *cur2){
		if(cur2->next == NULL){
			return cur2;
		}
		ListNode *temp = reverse(cur2->next);
		temp->next = cur2;
		return cur2;
	}

    void reorderList(ListNode *head) {
        ListNode *head1 = head;
        ListNode *head2 = NULL;
        ListNode *cur1 = head;
        ListNode *cur2 = head;
        ListNode *temp1 = NULL;
        ListNode *temp2 = NULL;
        ListNode *temp1_next = NULL;
        ListNode *temp2_next = NULL;
        int side = 1;

    	//1s
        if(head ==NULL)
        	return;
        else if(head->next == NULL)
        	return;
        else if(head->next->next == NULL)
        	return;
        
        while( cur1->next != NULL){
        	if(cur1->next->next != NULL){
        		cur1 = cur1->next->next;
        		cur2 = cur2->next;
        		continue;
        	}
        	break;
        }
        temp1 = cur2->next;
        cur2->next = NULL;
        cur2 = temp1;
        if(cur1->next != NULL)
        	cur1 = cur1->next;
        	
        printf("%d\n",cur1->val);
        head2 = cur1;
        reverse(cur2);
        cur2->next = NULL;
        
        //1e
        printf("hahah%d,%d\n",head1->val,head2->val);
        //2s
        temp1 = head1;
        temp2 = head2;
        
        while(true){
        	if(side == 1){
        		if(temp2 == NULL){
        			return;
        		}
        		else{
        			temp1_next = temp1->next;
        			temp1->next = temp2;
        			temp1 = temp1_next;
        			side = 2;
        			printf("%d\n",temp2->val);
        			continue;
        		}
        	}
        	else{
        		if(temp1 == NULL){
        			return;
        		}
        		else{
        			temp2_next = temp2->next;
        			temp2->next = temp1;
        			temp2 = temp2_next;
        			side = 1;
        			printf("%d\n",temp1->val);
        			continue;
        		}
        	}
        }
        
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
		
		reorderList(p1);
		ListNode* h = p1;
		while(h != NULL){
			printf("%d,",h->val);
			h = h->next;
		}
		
		
		
		
		return 0;
		
	}
	
	
	
