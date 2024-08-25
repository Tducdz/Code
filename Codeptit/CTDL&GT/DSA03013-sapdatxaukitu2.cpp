#include<bits/stdc++.h>

using namespace std;

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        int n, res = 0;
        cin >> n;
        int dd[30] = {};
        string s;
        cin >> s;
        for(char &i : s) ++dd[i - 'A'];
        for(int i = 0; i < 26; i++) res = max(res, dd[i]);
        int k = s.size() - (n - 1) * (res - 1);
        if(res <= k) cout << 1;
        else cout << -1;
        cout << endl;
    }
    return 0;
}