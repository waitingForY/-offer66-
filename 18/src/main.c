
#include <stdio.h>
#include <stdlib.h>
#define YES 1
#define NOT 0 
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

int hasSameSubTree(struct BTreeNode* root1,struct BTreeNode* root2)
{
	if(root2==NULL)
	  return YES;
	if(root1==NULL)
	  return NOT;
	if(root1->val!=root2->val)
	  return NOT;
	return hasSameSubTree(root1->left,root2->left) && hasSameSubTree(root1->right,root2->right);
}

int hasSubTree(struct BTreeNode* root1,struct BTreeNode* root2)
{
	int has=0;
	if(root1&&root2)
	{
		if(root1->val==root2->val)
		  has=hasSameSubTree(root1,root2);
		if(!has)
		  hasSubTree(root1->left,root2);
		if(!has)
		  hasSubTree(root1->right,root2);
	}
	return has;
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
	struct BTreeNode* root2=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	struct BTreeNode* node2_=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	struct BTreeNode* node3_=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	root2->val=8;
	root2->left=node2_;
	root2->right=node3_;
	node2_->val=9;
	node2_->left=NULL;
	node2_->right=NULL;
	node3_->val=2;
	node3_->left=NULL;
	node3_->right=NULL;
	printf("preorder of root1:");
	preorder(root1);
	printf("\n");
	printf("preorder of root2:");
	preorder(root2);
	printf("\n");

	char *result=hasSubTree(root1,root2)==YES ? "yes":"no";
	printf("has or not:%s\n",result);
	return 0;

}
