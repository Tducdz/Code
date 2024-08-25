#include<bits/stdc++.h>
using namespace std;

string solve(string s) {
    stack<int> st;
    string kq = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
            kq += "-1";
        }
        else if (s[i] == ')') {
            if (!st.empty()) {
                int op = st.top();
                st.pop();
                if (i == s.length() - 1 || s[i + 1] != ')') {
                    kq[op] = '0';
                    kq += '1';
                }
                else {
                    kq[op] = '0';
                    kq[i] = '1';
                }
            }
            else {
                kq += "-1";
            }
        }
        else {
            kq += s[i];
        }
    }
    return kq;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        cout << solve(s) << endl;
    }
    return 0;
}