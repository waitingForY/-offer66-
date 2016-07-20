
#include <stdio.h>
#include <stdlib.h>
struct BTreeNode
{
	int val;
	struct BTreeNode* left;
	struct BTreeNode* right;
};

void inorder(struct BTreeNode* root)
{
	if(root==NULL)
	  return;
	if(root->left)
	  inorder(root->left);
	printf("%d,",root->val);
	if(root->right)
	  inorder(root->right);
}


void printlist(struct BTreeNode* head)
{
	struct BTreeNode* p=head;
	while(p)
	{
		printf("%d,",p->val);
		p=p->right;
	}
}

void convertnode(struct BTreeNode* root,struct BTreeNode**last)
{
	if(root==NULL)
	  return;
	struct BTreeNode* current=root;
	if(current->left)
	  convertnode(current->left,last);
	current->left=*last;
	if(*last)
	  (*last)->right=current;
	*last=current;
	if(current->right)
	  convertnode(current->right,last);
}


struct BTreeNode* convert(struct BTreeNode* root)
{
	struct BTreeNode* last=NULL;
	convertnode(root,&last);
	struct BTreeNode* head=last;
	while(head&&head->left)
	  head=head->left;
	return head;
}



int main(void)
{
	struct BTreeNode* root1=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	root1->val=10;
	struct BTreeNode* node1=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node1->val=6;
	struct BTreeNode* node2=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node2->val=14;
	struct BTreeNode* node3=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node3->val=4;
	struct BTreeNode* node4=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node4->val=8;
	struct BTreeNode* node5=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node5->val=12;
	struct BTreeNode* node6=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node6->val=16;
	root1->left=node1;
	root1->right=node2;
	node1->left=node3;
	node1->right=node4;
	node2->left=node5;
	node2->right=node6;
	node3->left=NULL;
	node3->right=NULL;
	node4->left=NULL;
	node4->right=NULL;
	node5->left=NULL;
	node5->right=NULL;
	node6->left=NULL;
	node6->right=NULL;
	printf("before change:");
	inorder(root1);
	printf("\nafter change:");
	struct BTreeNode* head=convert(root1);
	printlist(head);
	printf("\n");
	return 0;
}
