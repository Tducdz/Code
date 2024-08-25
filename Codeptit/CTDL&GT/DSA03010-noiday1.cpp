#include<bits/stdc++.h>

using namespace std;

int main() {
    int t = 1, n, tmp;
    cin >> t;
    while(t--) {
        long long sum = 0;
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        while(n--) {
            cin >> tmp;
            pq.push(tmp);
        }
        while(pq.size() > 1)
        {
            tmp = pq.top();
            pq.pop();
            tmp += pq.top();
            pq.pop();
            sum += tmp;
            pq.push(tmp);
        }
        cout << sum << endl;
    }
    return 0;
}