// https://practice.geeksforgeeks.org/problems/next-larger-element/0

/*
This algorithm finds the next larger element in an array.
We loop through the array from the end; we initialize a null stack.
For each step, we remove from the stack all the elements which are smaller than the current element in the array;
then we output the first element of the stack, and then append the current element.

The running time is O(n), because we only input n elements in the stack, and the cost is given by pop and push operations.

The algorithm gives the right answer beacause at each step the stack is ordered (the first element is the smallest), and if A[j] is the next largest element to A[i], when we look at A[i] we delete every A[k] between A[i] and A[j], so A[j] is at the top of the stack.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n, x;
    cin >> T;
    vector<int> vec;
    vector<int> res;
    for (int i=0; i<T; i++) {
        cin >> n;
        vec.reserve(n);
        res.reserve(n);
        for (int j=0; j<n; j++) {
            cin >> x;
            vec.push_back(x);
        }

        stack<int> s;
        for (int j=vec.size()-1; j>=0; j--) {
            while (!s.empty() && vec[j] > s.top()) s.pop();
            if (s.empty()) res.push_back(-1);
            else res.push_back(s.top());
            s.push(vec[j]);
        }

        for (int j=res.size()-1; j>=0; j--) {
            cout << res[j] << " ";
        }
        cout << endl;
        vec.clear();
        res.clear();
    }

    return 0;
}
