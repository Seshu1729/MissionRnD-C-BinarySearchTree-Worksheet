/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node
{
  	struct node * left;
  	int data;
  	struct node *right;
};

int index_of_second_number(int **Arr, int len)
{
    int index = len;
    while (index--)
    {
      if (*Arr[index] < *Arr[index - 1])
        return index;
    }
    return -1;
}

int index_of_first_number(int **Arr, int len, int number)
{
    int start = 0, end = len, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if(mid==0)
          break;
        else if (*Arr[mid]>number && *Arr[mid - 1] <= number)
          break;
        else if (*Arr[mid]<number)
          start = mid + 1;
        else
          end = mid - 1;
    }
    return mid;
}

void swap_address(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void * sorted_array_positions_change(int **Arr, int len)
{
    int index1, index2;
    if (Arr != NULL)
    {
        index1 = index_of_second_number(Arr, len);
        if (index1 != -1)
        {
            index2 = index_of_first_number(Arr, index1, *Arr[index1]);
            swap_address(Arr[index1], Arr[index2]);
        }
    }
    return NULL;
}

int total_number_of_nodes_in_tree(struct node *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + total_number_of_nodes_in_tree(root->left) + total_number_of_nodes_in_tree(root->right);
}

void inorder(struct node *root, int **arr)
{
    if (root != NULL && arr!=NULL)
    {
        inorder(root->left, arr);
        *(arr + total_number_of_nodes_in_tree(root->left)) = &root->data;
        inorder(root->right, (arr + 1 + total_number_of_nodes_in_tree(root->left)));
    }
}

void fix_bst(struct node *root)
{
    int number_of_nodes = total_number_of_nodes_in_tree(root),**tree_data;
    tree_data = (int **)malloc(sizeof(int *)*number_of_nodes);
    inorder(root,tree_data);
    sorted_array_positions_change(tree_data,number_of_nodes);
}