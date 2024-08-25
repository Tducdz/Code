#include<bits/stdc++.h>
using namespace std;
string s;
int F[45];
int solve() {
    int n = s.size();
    if (s[0] == '0') return 0;
    else F[1] = 1;
    F[0] = 1;
    for (int i = 2;i <= n; i++) {
        F[i] = 0;
        if (s[i - 1] > '0') F[i] += F[i - 1];
        if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')
            F[i] += F[i - 2];
    }
    return F[n];
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        cout << solve() << endl;
    }
}