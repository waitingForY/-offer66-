
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct BTreeNode
{
	int val;
	struct BTreeNode* left;
	struct BTreeNode* right;
};

void findPaht(struct BTreeNode* root,int expected_sum,vector<int>&path,int &current_sum)
{

}

void findPath(struct BTreeNode* root,int expected_sum)
{
	if(root==NULL)
	  return;
	int current_sum=0;
	vector<usingt> path;
	findPath(root,expected_sum,path,current_sum);

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
