#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArraySum(const vector<int> &A) {
    int max_so_far = A[0];
    int max_ending_here = A[0];
    for (int i = 1; i < A.size(); ++i) {
        max_ending_here = max(A[i], max_ending_here + A[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        int max_sum = maxSubArraySum(A);
        cout << max_sum << endl; 
    }
    return 0;
}