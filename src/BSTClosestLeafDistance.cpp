/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node
{
    struct node * left;
    int data;
    struct node *right;
};

int min(int a,int b)
{
    if(a<b)
        return a;
    return b;
}

int get_minimum_distance(struct node *root)
{
    int min_height_of_left_subtree, min_height_of_right_subtree;
    if ((root->left == NULL && root->right==NULL)||root==NULL)
        return 0;
    else if(root->left==NULL && root->right!=NULL)
        return 1 + get_minimum_distance(root->right);
    else if(root->right==NULL && root->left!=NULL)
        return 1 + get_minimum_distance(root->left);
    else
    {
        min_height_of_right_subtree = get_minimum_distance(root->right);
        min_height_of_left_subtree = get_minimum_distance(root->left);
        return 1 + min(min_height_of_right_subtree,min_height_of_left_subtree);
    }
}

int get_closest_leaf_distance_recursively(struct node *root, struct node *temp,int min_distance)
{
    int current_min_distance;
    current_min_distance = min(get_minimum_distance(root),min_distance);
    if(root==temp)
        return current_min_distance;
    else if(root->data<temp->data)
        return get_closest_leaf_distance_recursively(root->right,temp,current_min_distance+1);
    else
        return get_closest_leaf_distance_recursively(root->left,temp,current_min_distance+1);
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
    int result,min_distance;
    if(root==NULL||temp==NULL)
        return -1;
    min_distance = get_minimum_distance(root);
    result = get_closest_leaf_distance_recursively(root,temp,min_distance);
    return result;
}
