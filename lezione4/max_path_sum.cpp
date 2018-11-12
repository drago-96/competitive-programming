// https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

/*
This algorithm finds the largest path sum between two leaves in a tree.
For every node we recursively compute the path with the largest sum from the node to any leaf in its left subtree and to any leaf in its right subtree;
then we check if the path obtained by joining these two paths has a sum larger than the current maximum.
The algorithm is correct because every path between two leaves is exactly of the type described: the union of two chains joined at the lower common ancestor of the leaves.

The running time is O(n) beacause we are running a BSF on the tree, with a constant number of sums made at each node.
*/

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
};
Node *newNode(int data){
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
int maxPathSum(struct Node *root);
void insert(Node *root, int a1,int a2, char lr){
    if(root==NULL)
        return ;
    if(root->data==a1){
        switch(lr){
            case 'L':root->left=newNode(a2);
                    break;
            case 'R':root->right=newNode(a2);
                    break;
        }
    }
    insert(root->left,a1,a2,lr);
    insert(root->right,a1,a2,lr);
}
void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *root=NULL;
        while(n--){
            int a1,a2;
            char lr;
            cin>>a1>>a2>>lr;
            if(root==NULL){
                root=newNode(a1);
                switch(lr){
                    case 'L':root->left=newNode(a2);
                            break;
                    case 'R':root->right=newNode(a2);
                            break;
                }
            }
            else
                insert(root,a1,a2,lr);
        }
        //inorder(root);
        //cout<<endl;
        cout<<maxPathSum(root)<<endl;
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows
struct Node{
    int data;
    Node *left, *right;
};
*/
//long max_path = -100000;

int longestChain(struct Node *root, int *max_path) {
    if (root==NULL) return 0;
    int l, r;
    l = longestChain(root->left, max_path);
    r = longestChain(root->right, max_path);
    if (l+r+root->data > *max_path) *max_path = l+r+root->data;
    if (r>l) return r+root->data;
    return l+root->data;
}


int maxPathSum(struct Node *root){
    int max_path = -100000;
    int a = longestChain(root, &max_path);
    return max_path;
}
