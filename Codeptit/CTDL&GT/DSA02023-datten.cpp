#include<bits/stdc++.h>

using namespace std;

int n, k;
vector<string> vs, ans;
int b[35];

void print() {
    for(int i = 1; i <= k; ++i) cout << vs[b[i] - 1] << ' ';
    cout << endl;
}

void Try(int i) {
    for(int j = b[i - 1] + 1; j <= vs.size() - k + i; ++j) {
        b[i] = j;
        if(i == k) print();
        else Try(i + 1);
    }
}

int main() {
    cin >> n >> k;
    string s;
    map<string, bool> m;
    for(int i = 0; i < n; ++i) {
        cin >> s;
        m[s] = 1;
    }
    for(auto &i : m) vs.push_back(i.first);
    Try(1);
    return 0;
}