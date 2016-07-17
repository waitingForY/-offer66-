#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};


struct ListNode* mergeSortedList(struct ListNode* list1,struct ListNode* list2)
{
	if(list1==NULL)
	  return list2;
	else if(list2==NULL)
	  return list1;
	struct ListNode* mergeHead=NULL;
	if(list1->val<=list2->val)
	{
		mergeHead=list1;
		mergeHead->next=mergeSortedList(list1->next,list2);
	}
	else
	{
		mergeHead=list2;
		mergeHead->next=mergeSortedList(list1,list2->next);
	}
	return mergeHead;
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
	struct ListNode* list1=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node5=(struct ListNode*)malloc(sizeof(struct ListNode));
	list1->val=1;
	list1->next=node2;
	node2->val=3;
	node2->next=node3;
	node3->val=5;
	node3->next=node4;
	node4->val=7;
	node4->next=node5;
	node5->val=9;
	node5->next=NULL;
	struct ListNode* list2=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2_=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3_=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4_=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node5_=(struct ListNode*)malloc(sizeof(struct ListNode));
	list2->val=2;
	list2->next=node2_;
	node2_->val=4;
	node2_->next=node3_;
	node3_->val=6;
	node3_->next=node4_;
	node4_->val=8;
	node4_->next=node5_;
	node5_->val=10;
	node5_->next=NULL;

	printf("list1:");
	printList(list1);
	printf("list2:");
	printList(list2);
	//printf("after merge:");
	//printList(mergeSortedList(list1,list2));
	struct ListNode* result=mergeSortedList(list1,list2);
	if(result)
	{
	  printf("after merge:");
	  printList(result);
	}
	else
	{
		printf("empty list\n");
	}
	
	return 0;
}
