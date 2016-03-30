/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node
{
	struct node * left;
	int data;
	struct node *right;
};

//  METHOD 1:
//  Using Helper Functions
//  Better Apporach then Method 2

void inorder_helper(struct node *root, int *arr, int *index)
{
    if (root != NULL && arr!=NULL)
    {
        inorder_helper(root->left, arr,index);
        arr[(*index)++] = root->data;
        inorder_helper(root->right, arr,index);
    }
}

void inorder(struct node *root, int *arr)
{
	int index = 0;
	inorder_helper(root,arr,&index);
}

void preorder_helper(struct node *root, int *arr, int *index)
{
    if (root != NULL && arr!=NULL)
    {
        arr[(*index)++] = root->data;
        preorder_helper(root->left, arr,index);
        preorder_helper(root->right, arr,index);
    }
}

void preorder(struct node *root, int *arr)
{
	int index = 0;
	preorder_helper(root,arr,&index);
}

void postorder_helper(struct node *root, int *arr, int *index)
{
    if (root != NULL && arr!=NULL)
    {
        postorder_helper(root->left, arr,index);
        postorder_helper(root->right, arr,index);
        arr[(*index)++] = root->data;
    }
}

void postorder(struct node *root, int *arr)
{
	int index = 0;
	postorder_helper(root,arr,&index);
}

/*

//  METHOD 2:: 
//  Using recursive function without using any helper functions Other Then total_number_of_nodes

int total_number_of_nodes(struct node *root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + total_number_of_nodes(root->left) + total_number_of_nodes(root->right);
}

void inorder(struct node *root, int *arr)
{
	if (root != NULL && arr!=NULL)
	{
		inorder(root->left, arr);
		*(arr + total_number_of_nodes(root->left)) = root->data;
		inorder(root->right, (arr + 1 + total_number_of_nodes(root->left)));
	}
}

void preorder(struct node *root, int *arr)
{
	if (root != NULL && arr != NULL)
	{
		*arr = root->data;
		preorder(root->left, ++arr);
		preorder(root->right, (arr + total_number_of_nodes(root->left)));
	}
}

void postorder(struct node *root, int *arr)
{
	if (root != NULL && arr != NULL)
	{
		postorder(root->left, arr);
		postorder(root->right, (arr + total_number_of_nodes(root->left)));
		*(arr + total_number_of_nodes(root->right) + total_number_of_nodes(root->left)) = root->data;
	}
}

*/