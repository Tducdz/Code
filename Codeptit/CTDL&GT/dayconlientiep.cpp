#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int &i : a)
        cin >> i;
    int MAX = -1;
    for(int i = 1; i < n; ++i)
        MAX = max(MAX, a[i]);
    int res = 0, cur = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == MAX)
            ++cur;
        else
        {
            res = max(res, cur);
            cur = 0;
        }
    }
    cout << max(res, cur);
    return 0;
}