#include<bits/stdc++.h>
using namespace std;
int main() {
    int d[5001][5001];
    int n, m;
    cin >> n >> m;
    int s1[n + 1], s2[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> s1[i] >> s2[i]; 
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] = max(max(d[i][j - 1], d[i - 1][j]), (j >= s1[i] ? d[i - 1][j - s1[i]] + s2[i] : 0));
        }
        cout << d[n][m];
    }
}