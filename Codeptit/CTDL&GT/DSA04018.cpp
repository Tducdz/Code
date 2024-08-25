#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << lower_bound(a.begin(), a.end(), 1) - a.begin() << endl;
    }
    return 0;
}