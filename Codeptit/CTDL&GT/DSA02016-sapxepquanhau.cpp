#include<bits/stdc++.h>

using namespace std;

int n, x[20], cnt;
bool col[100], a[100], b[100];

void Try(int i) {
    for(int j = 1; j < n + 1; ++j) {
        if(!col[j] and !a[i - j + n] and !b[i + j -1]) {
            col[j] = 1;
            a[i - j + n] = 1;
            b[i + j - 1] = 1;
            if (i == n) ++cnt;
            else Try(i + 1);
            col[j] = 0;
            a[i - j + n] = 0;
            b[i + j - 1] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        cnt = 0;
        Try(1);
        cout << cnt << endl;
    }
    return 0;
}