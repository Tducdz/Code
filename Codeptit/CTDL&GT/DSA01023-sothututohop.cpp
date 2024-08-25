#include<bits/stdc++.h>

using namespace std;

int n, k;
bool f[20];
vi a, v;
int cnt = 0;
bool ok;

bool check()
{
    return a == v;
}

void Try(int i)
{
    if(ok) return;
    for(int j = v[i - 1] + 1; j <= n - k + i; ++j)
    {
        v[i] = j;
        if(i == k)
        {
            ++cnt;
            if(check())
            {
                ok = 1;
                return;
            }
        }
        else Try(i + 1);
        if(ok) return;
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        ok = 0;
        cnt = 0;
        cin >> n >> k;
        a.resize(n + 1);
        v.resize(n + 1);
        memset(f, 0, 20);
        for(int i = 1; i <= k; ++i) cin >> a[i];
        Try(1);
        cout << cnt << endl;
    }
    return 0;
}