#include<bits/stdc++.h>

using namespace std;

int main() {
    int t = 1, n, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        queue<int> q;
        stack<string> st;
        for(int i = 0; i < n; ++i)
        {
            cin >> x;
            q.push(x);
        }
        for(int i = 1; i <= n; ++i)
        {
            string s = "";
            s += '[';
            for(int j = n - i; j >= 0; --j)
            {
                x = q.front();
                s += to_string(x);
                if(j) s += ' ';
                q.pop();
                x += q.front();
                if(j) q.push(x);
            }
            s += "] ";
            st.push(s);
        }
        while(st.size())
        {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
    return 0;
}