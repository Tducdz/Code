#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<string> vs;
    vs.push_back("66");
    vs.push_back("88");
    queue<string> q;
    q.push("6");
    q.push("8");
    string s1, s2, top;
    while(vs.size() < 10005) {
        top = q.front();
        q.pop();
        s1 = top + '6';
        s2 = top + '8';
        q.push(s1);
        q.push(s2);
        reverse(s1.begin(), s1.end());
        vs.push_back(top + '6' + s1);
        reverse(s2.begin(), s2.end());
        vs.push_back(top + '8' + s2);
    }
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << vs[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}