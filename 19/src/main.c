
#include <stdio.h>
#include <stdlib.h>
struct BTreeNode
{
	int val;
	struct BTreeNode* left;
	struct BTreeNode* right;
};

void preorder(struct BTreeNode* root)
{
	if(root==NULL)
	  return;
	printf("%d,",root->val);
	if(root->left)
	  preorder(root->left);
	if(root->right)
	  preorder(root->right);
}


void mirroTree(struct BTreeNode* root)
{
	if(root==NULL||(root->left==NULL&&root->right==NULL))
	  return;
	struct BTreeNode* tmp=root->left;
	root->left=root->right;
	root->right=tmp;
	if(root->left)
	  mirroTree(root->left);
	if(root->right)
	  mirroTree(root->right);
}

int main(void)
{
	struct BTreeNode* root1=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	root1->val=8;
	struct BTreeNode* node1=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node1->val=8;
	struct BTreeNode* node2=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node2->val=7;
	struct BTreeNode* node3=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node3->val=9;
	struct BTreeNode* node4=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node4->val=2;
	struct BTreeNode* node5=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node5->val=4;
	struct BTreeNode* node6=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node6->val=7;
	root1->left=node1;
	root1->right=node2;
	node1->left=node3;
	node1->right=node4;
	node2->left=NULL;
	node2->right=NULL;
	node3->left=NULL;
	node3->right=NULL;
	node4->left=node5;
	node4->right=node6;
	node5->left=NULL;
	node5->right=NULL;
	node6->left=NULL;
	node6->right=NULL;
	printf("before change:");
	preorder(root1);
	printf("\nafter change:");
	mirroTree(root1);
	preorder(root1);
	printf("\n");
	return 0;
}
