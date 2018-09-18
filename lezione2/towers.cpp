#include <bits/stdc++.h>

using namespace std;

int numbers[1001];

int main() {
    int N, c;
    int count = 0;
    cin >> N;
    int max = 0;
    for (int i=0; i<N; i++) {
        cin >> c;
        if (numbers[c] == 0) {
            count++;
        }
        numbers[c]++;
        if (numbers[c] > max) {
            max = numbers[c];
        }
    }
    cout << max << " " << count << endl;
    return 0;
}
