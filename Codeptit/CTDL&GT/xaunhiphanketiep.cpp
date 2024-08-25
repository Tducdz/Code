#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    string s;
    while (t--) {
        cin >> s;
        int x = s.size() - 1;
        while (s[x] == '1') {
            s[x] = '0';
            x--;
        }
        if (x >= 0) s[x] = '1';
        cout << s << endl;
    }
    return 0;
}