#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> dp(M + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = a[i]; j <= M; ++j) {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }

    cout << dp[M] << endl;
    return 0;
}

