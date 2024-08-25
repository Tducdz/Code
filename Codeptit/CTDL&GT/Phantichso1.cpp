#include<bits/stdc++.h>
using namespace std;

int n, a[100];

void in(int n) {
    cout << "(";
    for (int i = 1; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << a[n] << ") ";
}

void quaylui(int x, int i, int s) {
    for (int j = x; j >= 1; j--) {
        a[i] = j;
        if (j == s) in(i);
        else if (j < s) quaylui(j, i + 1, s - j);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        quaylui(n, 1, n);
        cout << endl;
    }
    return 0;
}