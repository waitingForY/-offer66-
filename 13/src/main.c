#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

void deleteNode(struct ListNode* head,struct ListNode* delp)
{
	if(head==NULL)
	  return;
	if(delp==head&&head->next==NULL)
	{
		free(delp);
		delp=NULL;
	}
	else if(delp!=head&&delp->next==NULL)
	{
		struct ListNode* p=head;
		while(p->next)
		  p=p->next;
		p->next=NULL;
		free(delp);
		delp=NULL;
	}
	else
	{
		struct ListNode* newdel=delp->next;
		delp->val=newdel->val;
		delp->next=newdel->next;
		free(newdel);
	}
}

void printList(struct ListNode* head)
{
	struct ListNode* p=head;
	while(p)
	{
		printf("%d,",p->val);
		p=p->next;
	}
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
	printList(head);
	deleteNode(head,node2);
	printList(head);
	return 0;
}
