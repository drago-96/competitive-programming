// https://practice.geeksforgeeks.org/problems/check-for-bst/1

/*
To see if a tree is a BST, we recursively check that each node is greater than all the nodes on its left subtree, and smaller than all the nodes on its right subtree.

The running time is O(n), beacause we check each node exactly once.
*/

#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
/* Returns true if the given tree is a binary search tree
 (efficient version). */
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main() {
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--){
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--){
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end()){
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isBST(root) << endl;
  }
  return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node* left, * right;
}; */
/* Should return true if tree represented by root is BST.
   For example, return  value should be 1 for following tree.
         20
     /      \
   10       30
  and return value should be 0 for following tree.
         10
     /      \
   20       30 */

struct dati{
    int max, min;
    bool is_BST;
};

dati isBST_helper(Node* root) {
    struct dati data;
    if (root==NULL) {
        data.is_BST = true;
        data.max = -10000;
        data.min = 10000;
        return data;
    }
    struct dati left, right;
    left = isBST_helper(root->left);
    right = isBST_helper(root->right);
    if (!left.is_BST || !right.is_BST) {
        data.is_BST = false;
        return data;
    }
    if (left.max > root->data || right.min < root->data) {
        data.is_BST = false;
        return data;
    }
    data.min = (left.min != 10000 ? left.min : root->data);
    data.max = (right.max != -10000 ? right.max : root->data);
    data.is_BST = true;
    return data;
}

bool isBST(Node* root) {
    struct dati res = isBST_helper(root);
    return res.is_BST;
}
