#include<iostream>
using namespace std;

int main() {
    int t = 1, n, idx;
    cin >> t;
    while(t--) {
        int cnt = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            idx = i;
            for(int j = i + 1; j < n; ++j) {
                if(a[idx] > a[j]) idx = j;
            }
            if (idx != i) cnt++;
            swap(a[i], a[idx]);
        }
        cout << cnt << endl;
    }
    return 0;
}