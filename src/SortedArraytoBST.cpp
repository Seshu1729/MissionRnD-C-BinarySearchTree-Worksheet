/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node
{
	struct node * left;
	int data;
	struct node *right;
};

struct node *get_node()
{
	struct node *new_node;
	new_node = (struct node *) malloc(sizeof(struct node));
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

struct node *convert_array_to_bst_main(int *arr, int start, int end)
{
	int mid;
	struct node *new_node = NULL;
	if (start<end)
	{
		mid = (start + end) / 2;
		new_node = get_node();
		new_node->data = arr[mid];
		new_node->left = convert_array_to_bst_main(arr, start, mid);
		new_node->right = convert_array_to_bst_main(arr, mid + 1, end);
	}
	return new_node;
}

struct node * convert_array_to_bst(int *arr, int len)
{
	if (arr == NULL)
		return NULL;
	else
		return convert_array_to_bst_main(arr, 0, len);
}

