#include<bits/stdc++.h>

using namespace std;

 
int main()
{
    int t = 1, n, k, x;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        int i = s.length() - 1;
        while(s[i] == '0')
        {
            s[i] = '1';
            --i;
        }
        if(i < 0) for (int i = 0; i < s.length(); i++) cout << 1;
        else
        {
            s[i] = '0';
            cout << s;
        }
        cout << endl;
    }
    return 0;
}