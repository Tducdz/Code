#include<bits/stdc++.h>

using namespace std;

inline bool check(string &s)
{
    stack<char> st;
    for(char &i : s)
    {
        if(i == '(')
            st.push(i);
        else
        {
            if(st.empty())
                return 0;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    int t = 1;
    cin >> t;
    while(t--)
    {
        string tmp;
        cin >> tmp;
        string s = "";
        for(char &i : tmp)
            if(i == ')' or i == '(')
                s += i;
        if(!check(s))
        {
            cout << -1 << endl;
            continue;
        }
        int cnt = 0, res = 0;
        for(char &i : s)
        {
            if(i == '(')
            {
                ++cnt;
                res = max(res, cnt);
            }
            else
                --cnt;
        }
        cout << res << endl;
    }
    return 0;
}