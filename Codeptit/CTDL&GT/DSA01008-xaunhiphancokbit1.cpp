#include<bits/stdc++.h>

using namespace std;

int n, k, a[20] = {};

void print()
{
    for (int i = 1; i <= n; ++i) cout << a[i];
    cout << endl;
}
 
void Try(int i)
{
    for (int j = 0; j <= 1; ++j)
    {
        a[i] = j;
        if(i == n)
        {
            int cnt = 0;
            for (int i = 1; i <= n; ++i) cnt += a[i];
            if(cnt == k) print();
        }
        else Try(i + 1);
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        Try(1);
    }
    return 0;
}