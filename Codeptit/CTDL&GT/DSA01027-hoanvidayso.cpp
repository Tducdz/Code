#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    sort(a.begin(), a.end());
    for(int &i : a) cout << i << ' ';
    cout << endl;
    while(next_permutation(begin(a), end(a))) {
        for(int &i : a) cout << i << ' ';
        cout << endl;
    }
}