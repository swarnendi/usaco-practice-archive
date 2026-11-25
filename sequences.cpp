#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A;
int dp[105][105];

int get_min_prints(int L, int R) {
    if (L > R) return 0;
    if (dp[L][R] != -1) return dp[L][R];

    bool all_same = true;
    for (int i = L + 1; i <= R; i++) {
        if (A[i] != A[L]) {
            all_same = false;
            break;
        }
    }
    if (all_same) return dp[L][R] = 1;

    int min_cost = 1e9;

    for (int i = L; i < R; i++) {
        min_cost = min(min_cost, get_min_prints(L, i) + get_min_prints(i + 1, R));
    }

    int total_len = R - L + 1;
    for (int len = 1; len < total_len; len++) {
        if (total_len % len == 0) {
            bool is_periodic = true;
            for (int i = L; i <= R; i++) {
                if (A[i] != A[L + (i - L) % len]) {
                    is_periodic = false;
                    break;
                }
            }
            if (is_periodic) {
                min_cost = min(min_cost, get_min_prints(L, L + len - 1));
            }
        }
    }

    return dp[L][R] = min_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            int N, K;
            if (!(cin >> N >> K)) break;

            A.resize(N);
            for (int i = 0; i < N; i++) {
                cin >> A[i];
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dp[i][j] = -1;
                }
            }

            if (get_min_prints(0, N - 1) <= K) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
