#include<bits/stdc++.h>

using namespace std;

int check(string &s) {
    int f[130] = {};
    int MAX = 0;
    for (int i = 0; i < s.length(); i++) {
        ++f[s[i]];
        MAX = max(f[s[i]], MAX);
    }
    if (MAX <= s.length() - MAX + 1) return 1;
    return -1;
}

int main() {
    int t = 1;
    string s;
    cin >> t;
    while(t--) {
        cin >> s;
        cout << check(s) << endl;
    }
    return 0;
}