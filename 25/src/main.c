
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

void findPath(struct BTreeNode* root,int expected,vector<int> &path,int currentsum);

void findPath(struct BTreeNode* root,int expected)
{
	if(root==NULL)
	  return;
	vector<int> path;
	int currentsum=0;
	findPath(root,expected,path,currentsum);
}


void findPath(struct BTreeNode* root,int expected,vector<int> &path,int currentsum)
{
	currentsum+=root->val;
	path.push_back(root->val);
	int isleaf=(root->left==NULL)&&(root->right==NULL);
	if(currentsum==expected&&isleaf)
	{
		printf("find a path:\n");
		vector<int>::iterator it=path.begin();
		while(it!=path.end())
		{
			printf("%d,",*it);
			++it;
		}
		printf("\n");
	}
	if(root->left)
	  findPath(root->left,expected,path,currentsum);
	if(root->right)
	  findPath(root->right,expected,path,currentsum);
	currentsum-=root->val;
	path.pop_back();
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
	struct BTreeNode* node7=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node7->val=10;
	root1->left=node1;
	root1->right=node2;
	node1->left=node3;
	node1->right=node4;
	node2->left=node7;
	node2->right=NULL;
	node3->left=NULL;
	node3->right=NULL;
	node4->left=node5;
	node4->right=node6;
	node5->left=NULL;
	node5->right=NULL;
	node6->left=NULL;
	node6->right=NULL;
	node7->left=NULL;
	node7->right=NULL;
	findPath(root1,25);
	printf("\n");
	return 0;
}
