#include<bits/stdc++.h>

using namespace std;

inline bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int t = 1, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<pair<int, int>> vp(n);
        for(int i = 0; i < n; i++) cin >> vp[i].first >> vp[i].second;
        sort(vp.begin(), vp.end(), cmp);
        int cnt = 0;
        int last = 0;
        for(pair<int, int> i : vp) {
            if (i.first < last) continue;
            last = i.second;
            ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}