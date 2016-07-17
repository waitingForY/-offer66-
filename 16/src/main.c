#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* reverseHead=NULL;
	struct ListNode* pnode=head;
	struct ListNode* pprenode=NULL;
	while(pnode)
	{
		struct ListNode* pnext=pnode->next;
		if(pnext==NULL)
		  reverseHead=pnode;
		pnode->next=pprenode;
		pprenode=pnode;
		pnode=pnext;
	}
	return reverseHead;
}

void printList(struct ListNode* head)
{
	struct ListNode* p=head;
	if(p==NULL)
	{
		printf("empty list\n");
		exit(EXIT_FAILURE);
	}
	while(p)
	{
		printf("%d,",p->val);
		p=p->next;
	}
	printf("\n");
}

int main(void)
{
	struct ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node5=(struct ListNode*)malloc(sizeof(struct ListNode));
	head->val=1;
	head->next=node2;
	node2->val=2;
	node2->next=node3;
	node3->val=3;
	node3->next=node4;
	node4->val=4;
	node4->next=node5;
	node5->val=5;
	node5->next=NULL;
	printf("before reverse:");
	printList(head);
	printf("after reverse:");
	printList(reverseList(head));
	return 0;
}
