#include<bits/stdc++.h>

using namespace std;

int n;
int a[35] = {};
vector<string> vs;
vector<int> tmp;

inline void print()
{
    string s = "";
    for(int &i : tmp) s += to_string(i) + ' ';
    vs.push_back(s);
}

inline void Try(int i)
{
    for(int j = i + 1; j <= n; ++j)
    {
        if(a[j] > a[i])
        {
            tmp.push_back(a[j]);
            if(tmp.size() > 1) print();
            Try(j);
            tmp.pop_back();
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    Try(0);
    sort(begin(vs), end(vs));
    for(string &i : vs) cout << i << endl;
    return 0;
}