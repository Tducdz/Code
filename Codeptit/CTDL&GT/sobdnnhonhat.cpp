#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

queue<long long> hangcho;
long long solve(int n) {
    if (hangcho.empty()) {
        hangcho.push(1);
    }
    long long s = hangcho.front();
    hangcho.pop();
    if (s % n == 0) {
        return s;
    }
    else {
        hangcho.push(s*10);
        hangcho.push(s*10 + 1);
        return solve(n);
    }
}

int main() {
    int T;
    cin >> T;
    
    queue<long long> hangcho;

    while (T--) {
        int N;
        cin >> N;
        cout << solve(N) << endl;
    }

    return 0;
}
