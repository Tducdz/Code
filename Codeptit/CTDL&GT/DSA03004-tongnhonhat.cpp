#include<bits/stdc++.h>

using namespace std;

int main() {
    int t = 1, n, x;
    cin >> t;
    long long a, b;
    while(t--) {
        priority_queue<int, vector<int>, greater<int>> pq;
        cin >> n;
        while(n--) {
            cin >> x;
            pq.push(x);
        }
        a = b = 0;
        bool check = 0;
        while(pq.size()) {
            if(!check) a = a * 10 + pq.top();
            else b = b * 10 + pq.top();
            pq.pop();
            check ^= 1;
        }
        cout << a + b << endl;
    }
    return 0;
}