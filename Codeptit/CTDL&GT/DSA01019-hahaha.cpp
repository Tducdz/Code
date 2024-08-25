#include<bits/stdc++.h>

using namespace std;
int n;
vector<char> vc;
char a[2] = {'A', 'H'};

void print()
{
    for(int i = 1; i <= n; ++i) cout << vc[i];
    cout << endl;
}

void Try(int i)
{
    for(int j = 0; j < 2; ++j)
    {
        if(vc[i - 1] == 'H' and j == 1) continue;
        vc[i] = a[j];
        if(i == n - 1) print();
        else Try(i + 1);
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 2)
        {
            cout << "HA" << endl;
            continue;
        }
        vc.resize(n + 1);
        vc[1] = 'H';
        vc[n] = 'A';
        Try(2);
    }
    return 0;
}