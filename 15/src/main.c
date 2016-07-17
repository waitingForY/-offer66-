#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* printNok(struct ListNode* head,int k)
{
	if(head==NULL||k<=0)
	  return NULL;
	struct ListNode* pahead=head;
	int i;
	for(i=1;i<k&&pahead->next;i++)
		pahead=pahead->next;
	if(i!=k)
	  return NULL;
	struct ListNode* pafter=head;
	while(pahead->next)
	{
		pahead=pahead->next;
		pafter=pafter->next;
	}
	return pafter;
}

void printList(struct ListNode* head)
{
	struct ListNode* p=head;
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
	printList(head);
	int n;
	printf("input:");
	scanf("%d",&n);
	struct ListNode* result=printNok(head,n);
	if(result)
	  printf("result=%d\n",result->val);
	else
	  printf("error input\n");
	return 0;
}
