#include<bits/stdc++.h>
using namespace std;
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int &i : a) cin >> i;
        next_permutation(a.begin(), a.end());
        for (int i : a) cout << i << ' ';
        cout << endl;
    }
    return 0;
}