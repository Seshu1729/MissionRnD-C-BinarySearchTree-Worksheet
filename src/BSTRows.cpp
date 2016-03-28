/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node
{
	struct node * left;
	int data;
	struct node *right;
};

int number_of_nodes_in_tree(struct node *root)
{
	if(root==NULL)
		return 0;
	else
		return 1 + number_of_nodes_in_tree(root->left) + number_of_nodes_in_tree(root->right);
}

void store_result_as_structure(struct node **result_as_structure,int total_number_of_nodes)
{
	int storing_index = 0,retriving_index = 0;
	while(retriving_index<total_number_of_nodes)
	{
		if(result_as_structure[retriving_index]->right!=NULL)
		{
			storing_index++;
			result_as_structure[storing_index] = result_as_structure[retriving_index]->right;
		}
		if(result_as_structure[retriving_index]->left!=NULL)
		{
			storing_index++;
			result_as_structure[storing_index] = result_as_structure[retriving_index]->left;
		}
		retriving_index++;
	}
}

int *extract_result_from_array_of_structures(struct node **result_as_structure,int total_number_of_nodes)
{
	int *result,index;
	result = (int *)malloc(sizeof(int)*total_number_of_nodes);
	for(index=0;index<total_number_of_nodes;index++)
		result[index] = result_as_structure[index]->data;
	return result;
}

int* BSTRighttoLeftRows(struct node* root)
{
	struct node **result_as_structure;
	int total_number_of_nodes,*result;

	if(root==NULL)
		return NULL;

	total_number_of_nodes = number_of_nodes_in_tree(root);
	result_as_structure = (struct node **)malloc(sizeof(struct node *)*total_number_of_nodes);
	result_as_structure[0] = root;
	store_result_as_structure(result_as_structure,total_number_of_nodes);
	result = extract_result_from_array_of_structures(result_as_structure,total_number_of_nodes);
    return result;
}
