#include <bits/stdc++.h>

using namespace std;

void print(int *A, int N) {
    for(int i=0;i<N;i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

long merge_sort(int *A, int l, int r) {
    if (l==r) return 0;
    int m = l+(r-l)/2;
    long inv_l, inv_r, inv_t;
    inv_l = merge_sort(A,l,m);
    inv_r = merge_sort(A,m+1,r);
    inv_t = inv_l + inv_r;
    int tmp[r-l+1];
    int idx=0;
    int it=l;
    int i;
    for(int j=m+1;j<=r;j++) {
        for(i=it;i<=m;i++) {
            if (A[i]<A[j]) tmp[idx++]=A[i];
            else break;
        }
        it=i;
        inv_t += m-it+1;
        tmp[idx++]=A[j];
    }
    for(i=it;i<=m;i++) {
        tmp[idx++]=A[i];
    }
    for(i=l;i<=r;i++) {
        A[i]=tmp[i-l];
    }
    return inv_t;
}


int main() {
    ios::sync_with_stdio(false);
    int N, T;
    cin >> T;
    for(int i=0;i<T;i++) {
        cin >> N;
        int arr[N];
        for(int j=0;j<N;j++) {
            cin >> arr[j];
        }
        long res = merge_sort(arr,0,N-1);
        cout << res << endl;
    }

    return 0;
}
