#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<int> v(1, 0), a;

void print()
{
    for(int i = 1; i <= k; ++i) cout << v[a[i]] << ' ';
    cout << endl;
}

void Try(int i)
{
    for(int j = a[i - 1] + 1; j <= n - k + i; ++j)
    {
        a[i] = j;
        if(i == k) print();
        else Try(i + 1);
    }
}

int main()
{
    int t = 1;
    //cin >> t;
    while(t--)
    {
        bool f[1005] = {};
        int x;
        cin >> n >> k;
        for(int i = 0; i < n; ++i)
        {
            cin >> x;
            if(!f[x])
            {
                v.push_back(x);
                f[x] = 1;
            }
        }
        sort(begin(v), end(v));
        n = v.size() - 1;
        a.resize(v.size());
        Try(1);
    }
    return 0;
}
