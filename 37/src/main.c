#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};


int getlength(struct ListNode* list)
{
	int count=0;
	struct ListNode* p=list;
	while(p)
	{
		count++;
		p=p->next;
	}
	return count;
}

void find(struct ListNode* list1,struct ListNode* list2)
{
	int len1=getlength(list1);
	int len2=getlength(list2);
	struct ListNode* plonglist=len1>len2?list1:list2;
	struct ListNode* pshortlist=len1>len2?list2:list1;
	int dpartlength=len1>len2?(len1-len2):(len2-len1);
	int i=0;
	while(i++<dpartlength)
	  plonglist=plonglist->next;
	while(plonglist&&pshortlist&&plonglist!=pshortlist)
	{
		plonglist=plonglist->next;
		pshortlist=pshortlist->next;
	}
	printf("result=%d\n",plonglist->val);
}


int main(void)
{
	struct ListNode* list1=(struct ListNode*)malloc(sizeof(struct ListNode));
	list1->val=1;
	struct ListNode* node2=(struct ListNode*)malloc(sizeof(struct ListNode));
	node2->val=2;
	struct ListNode* node3=(struct ListNode*)malloc(sizeof(struct ListNode));
	node3->val=3;
	struct ListNode* list2=(struct ListNode*)malloc(sizeof(struct ListNode));
	list2->val=4;
	struct ListNode* node5=(struct ListNode*)malloc(sizeof(struct ListNode));
	node5->val=5;
	struct ListNode* node6=(struct ListNode*)malloc(sizeof(struct ListNode));
	node6->val=6;
	struct ListNode* node7=(struct ListNode*)malloc(sizeof(struct ListNode));
	node7->val=7;
	list1->next=node2;
	node2->next=node3;
	node3->next=node6;
	node6->next=node7;
	node7->next=NULL;
	list2->next=node5;
	node5->next=node6;
	find(list1,list2);
	return 0;
}
