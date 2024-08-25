#include<bits/stdc++.h>

using namespace std;

int main() {
    int t = 1, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int sum = 0, tmp = 0;
        vector<int> v(n);
        for(int &i : v) {
            cin >> i;
            sum += i;
        }
        sort(v.begin(), v.end());
        k = min(k, n - k);
        for(int i = 0; i < k; ++i) tmp += v[i];
        cout << sum - (tmp << 1) << endl;
    }
    return 0;
}