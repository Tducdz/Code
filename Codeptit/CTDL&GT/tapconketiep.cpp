#include<bits/stdc++.h>
using namespace std;
int main() {
    int t, n, k;
    cin >> t;
    string s;
    while (t--) {
        int a[1001];
        cin >> n >> k;
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
        }
        int dem = k;
        while (a[dem] == n - k + dem) dem--;
        if (dem > 0) {
            ++a[dem];
            for (int i = dem + 1; i <= k; i++) {
                a[i] = a[i - 1] + 1;
            }
            for (int i = 1; i <= k; i++) {
                cout << a[i] << ' ';
            }
        } 
        else for (int i = 1; i <= k; i++) cout << i << ' ';
        cout << endl;
    }
    return 0;
}