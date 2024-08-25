#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t = 1, n, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        queue<int> q;
        for(int i = 0; i < n; ++i)
        {
            cin >> x;
            q.push(x);
        }
        for(int i = 1; i <= n; ++i)
        {
            cout << '[';
            for(int j = n - i; j >= 0; --j)
            {
                x = q.front();
                cout << x;
                if(j) cout << ' ';
                q.pop();
                x += q.front();
                if(j) q.push(x);
            }
            cout << "]" << endl;
        }
    }
    return 0;
}