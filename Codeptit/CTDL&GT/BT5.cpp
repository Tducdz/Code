#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cin.ignore();
        string s;
        getline(cin, s);
        stack<long long> st;
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                st.push(s[i] - '0');
            }
            else if (s[i] != ' ') {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                switch (i) {

                case '+': 
                    st.push(a + b);
                    break;

                case '-':
                    st.push(a - b);
                    break;

                case '*': 
                    st.push(a * b);
                    break;

                case '/':
                    st.push(a / b);
                    break;
                }
            } 
        }
        cout << st.top() << endl;
    }
    return 0;
}