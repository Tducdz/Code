#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = abs(a[i].first - x);
        }
        stable_sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });
        for (int i = 0; i < n; i++) {
            cout << a[i].first << " ";
        }
        cout << endl;
    }
    return 0;
}