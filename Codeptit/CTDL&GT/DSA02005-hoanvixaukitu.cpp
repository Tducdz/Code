#include<bits/stdc++.h>

using namespace std;
int calc(int n)
{
    int res = 1;
    for(int i = 2; i <= n; ++i) res *= i;
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int cnt = calc((int) s.size());
        while(cnt--)
        {
            cout << s << ' ';
            next_permutation(begin(s), end(s));
        }
        cout << endl;
    }
    return 0;
}