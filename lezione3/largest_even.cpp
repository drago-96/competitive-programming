// https://practice.geeksforgeeks.org/problems/largest-even-number/0

/*
This algorithm finds the largest even number that can be formed with given digits.
First we count how may digits of every type we have available.
Then we look for the lowest even digit we can use, and put it as the last digit of the result.
Then we append digits at the left of our number in increasing order: by the rearrangement inequality this is the biggest number we can form.

The running time is linear in the number of digits of the input.
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    string num;
    cin >> T;
    for (int i=0; i<T; i++) {
      int digits[10] = {0};
      cin >> num;
      int n = num.length();
      for (int j=0;j<n;j++) {
        int r = num[j]-'0';
        digits[r]++;
      }

      string sres (num);
      int idx = n-1;
      int j=0;
      for (j=0;j<10;j+=2) {
        if (digits[j]>0) {
          digits[j]--;
          sres[idx--] = j+'0';
          break;
        }
      }

      if (j==10) idx=n-1;
      for (j=0;j<10;j++) {
        while (digits[j]>0) {
          sres[idx--] = j + '0';
          digits[j]--;
        }
      }

      cout << sres << endl;
    }

    return 0;
}
