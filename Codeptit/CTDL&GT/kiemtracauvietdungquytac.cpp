#include<bits/stdc++.h>

using namespace std;

string check(string &s) {
    stack<char> st;
    for(char &i : s) {
        if(i == '(' || i == '[')
            st.push(i);
        if(i == ')') {
            if(st.size() && st.top() == '(')
                st.pop();
            else
                return "NO";
        }
        else if(i == ']') {
            if(st.size() && st.top() == '[')
                st.pop();
            else
                return "NO";
        }
    }
    if(st.empty())
        return "YES";
    return "NO";
}

int main() {
    int t = 1;
    cin >> t;
    string s;
    cin.ignore();
    while(t--) {
        getline(cin, s);
        cout << check(s) << endl;
    }
    return 0;
}