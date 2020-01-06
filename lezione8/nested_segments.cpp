// http://codeforces.com/problemset/problem/652/D?locale=en

/*
We use a BIT in which the element at position i is the number of segments whose right end is exactly i.
We process the segments by decreasing value of their left ends; for each segment we add 1 to the number of segments ending at r_i.
Then the number of segments contained in the one being processed is the prefix sum until index r_i.

The running time is O(n*logn), given by the sorting and the n operations of Sum and Update on the BIT.
*/

#include <bits/stdc++.h>

using namespace std;

#define LSB(i) ((i) & -(i))

template <typename T>
struct BIT {
    T *arr;
    int size;

    BIT(int n) {
        arr = new T[n+1];
        size = n;
        for(int i=1;i<=size;i++) {
            arr[i] = T{};
        }
    }

    void update(int i, T val) {
        i++;
        while(i < size+1) {
            arr[i] += val;
            i += LSB(i);
        }
    }

    T sum(int r) {
        T sum = T{};
        int i = r+1;
        while(i > 0) {
            sum += arr[i];
            i -= LSB(i);
        }
        return sum;
    }
};

int main() {
    int N;
    long long l, r;
    vector< pair<long long, long long> > segments, newsegs;
    vector< pair<long long, int> > ends;

    cin >> N;
    newsegs.reserve(N);
    segments.reserve(N);
    ends.reserve(2*N);
    vector<int> indexes(N);
    for(int i=0;i<N;i++) {
        cin >> l >> r;
        segments.emplace_back(l,r);
        newsegs.emplace_back(l,r);
        ends.emplace_back(l,i);
        ends.emplace_back(r,i);

        indexes[i] = i;
    }

    sort(ends.begin(), ends.end());
    for (int i=0;i<2*N;i++) {
        if (ends[i].first == segments[ends[i].second].first) newsegs[ends[i].second].first = i;
        else newsegs[ends[i].second].second = i;
    }

    sort(indexes.begin(),indexes.end(),
        [&](const int& a, const int& b) {
            return (newsegs[a] > newsegs[b]);
        }
    );

    BIT<long long> bit = BIT<long long>(2*N);
    vector<int> results(N);
    for(int i=0;i<N;i++) {
        int idx = indexes[i];
        r = newsegs[idx].second;
        results[idx] = bit.sum(r);
        bit.update(r,1);
    }

    for(int i=0;i<N;i++) {
        cout << results[i] << endl;
    }

    return 0;
}
