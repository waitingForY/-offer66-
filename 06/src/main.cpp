#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

#include <sys/types.h>
#include <stack>

using namespace std;

struct BTreeNode
{
	int val;
	struct BTreeNode* left;
	struct BTreeNode* right;
};


struct BTreeNode* reconstructor(int *preorder_start,int *preorder_end,int *inorder_start,int *inorder_end)
{
	int root_val=*preorder_start;
	struct BTreeNode* root=(struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	root->val=root_val;
	root->left=root->right=NULL;
	if(preorder_start==preorder_end)
	{
		if(inorder_start==inorder_end&&*preorder_start==*inorder_start)
		  return root;
		else
		{
			printf("constructor error\n");
			exit(EXIT_FAILURE);
		}
	}
	int *root_inorder=inorder_start;
	while(root_inorder!=inorder_end&&*root_inorder!=root_val)
	  ++root_inorder;
	if(root_inorder==inorder_end&&*root_inorder!=root_val)
	{
		printf("constructor error\n");
		exit(EXIT_FAILURE);
	}
	
	int left_tree_length=root_inorder-inorder_start;
	int *left_tree_preorder_end=preorder_start+left_tree_length;

	if(left_tree_length>0)
	  root->left=reconstructor(preorder_start+1,left_tree_preorder_end,inorder_start,root_inorder-1);
	if(left_tree_length<preorder_end-preorder_start)
	  root->right=reconstructor(left_tree_preorder_end+1,preorder_end,root_inorder+1,inorder_end);
	return root;
}

struct BTreeNode* constructor(int *preorder,int *inorder,int len)
{
	if(preorder==NULL||inorder==NULL||len<=0)
	  return NULL;
	return reconstructor(preorder,preorder+len-1,inorder,inorder+len-1);
}
/*
 *下面是三个递归版本的遍历
 */
void printPreorder(struct BTreeNode* root)
{
	if(root)
	{
		printf("%d,",root->val);
		printPreorder(root->left);
		printPreorder(root->right);
	}
	else
	  return;
}

void printInorder(struct BTreeNode *root)
{
	if(root)
	{
		printInorder(root->left);
		printf("%d,",root->val);
		printInorder(root->right);
	}
	else
	  return;
}

void printLastOrder(struct BTreeNode* root)
{
	if(root)
	{
		printLastOrder(root->left);
		printLastOrder(root->right);
		printf("%d,",root->val);
	}
	else
	  return;
}
/*
 *下面是三个非递归版本的遍历；
 */
//这里我们利用c++stl中的stack来实现非递归的版本；
//必须包含头文件<stack.h>


void printPreorder_stack(struct BTreeNode* root)
{
	stack<struct BTreeNode*> node_stack;
	if(root)
	{
		node_stack.push(root);
		while(!node_stack.empty())
		{
			struct BTreeNode* tmp=node_stack.top();
			printf("%d,",tmp->val);
			node_stack.pop();
			if(tmp->right)
			  node_stack.push(tmp->right);
			if(tmp->left)
			  node_stack.push(tmp->left);
		}
	}
	else
	  return;
}


void printInorder_stack(struct BTreeNode* root)
{
	stack<struct BTreeNode*> node_stack;
	if(root)
	{
		node_stack.push(root);
		struct BTreeNode* lastleft=root;
		while(!node_stack.empty())
		{
			while(lastleft->left)
			{
				node_stack.push(lastleft->left);
				lastleft=lastleft->left;
			}
			struct BTreeNode* tmp=node_stack.top();
			printf("%d,",tmp->val);
			node_stack.pop();
			if(tmp->right)
			{
				lastleft=tmp->right;
				node_stack.push(lastleft);
			}
		}
	}
	else
	  return;
}

int main(void)
{
	int preorder[]={1,2,4,7,3,5,6,8};
	int inorder[]={4,7,2,1,5,3,8,6};
	struct BTreeNode* root=constructor(preorder,inorder,8);
	printf("preorder:");
	//printPreorder(root);
	printPreorder_stack(root);
	printf("\n");
	printf("inorder:");
	//printInorder(root);
	printInorder_stack(root);
	printf("\n");
	printf("lastorder:");
	printLastOrder(root);
	printf("\n");
	return 0;

}
