// https://practice.geeksforgeeks.org/problems/preorder-traversal-and-bst/0/

/*
An array is a preorder traversal of a BST if and only if it is of the form N, (integers less than N), (integer grater than N) and both block are recursively of the same form.
This is equivalent to saying that all the elements to the right of the next greater element are smaller than the original element.

So we use a stack to compute the next greatest element; in cur_root we keep the first node for which the current element is in the irght subtree of cur_root.

The running time is O(n) and the memory is O(n), beacause every element of the array enters and exits the stak exactly once.
*/

# include <bits/stdc++.h>
using namespace std;

bool is_preorder(int *arr, int n) {
    stack<int> s;
    int cur_root = -1;

    for (int i=0;i<n;i++) {

        if (arr[i]<cur_root) return false;

        while(!s.empty() && arr[i]>s.top()) {
            cur_root = s.top();
            s.pop();
        }

        s.push(arr[i]);
    }
    return true;
}


int main() {
    int T, n;
    cin >> T;
    for (int i=0;i<T;i++) {
        cin >> n;
        int arr[n];
        for (int j=0;j<n;j++) {
            cin >> arr[j];
        }
        cout << is_preorder(arr, n) << endl;
    }

    return 0;
}
