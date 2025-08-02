#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 30; // since 2^30 > 10^9

int up[MAXN][LOG];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> up[i][0];
    }

    // Precompute jump table
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }

    // Answer queries
    while (q--) {
        int x;
        long long k;
        cin >> x >> k;

        for (int i = 0; i < LOG; i++) {
            if (k & (1LL << i)) {
                x = up[x][i];
            }
        }

        cout << x << '\n';
    }
}
