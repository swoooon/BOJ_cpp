#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;
#define ct(x) cout << x << '\n'
#define ct2(x, y) cout << x << ' ' << y << '\n'
#define ct3(x, y, z) cout << x << ' ' << y << ' ' << z << '\n'
#define ct4(x, y, z, w) cout << x << ' ' << y << ' ' << z << ' ' << w << '\n'

const ll mod = 1e9+7;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};


ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}

void debug() {

}

int N, K;
int arr[1010];
int dp[1010][33][3];


void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    int ans = 0;
    for (int j = 1; j <= K+1; j++) {
        for (int i = 1; i <= N; i++) {
            if (arr[i] == 1) {
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][2]) + 1;
                dp[i][j][2] = max(dp[i-1][j-1][1], dp[i-1][j][2]);
            }
            else {
                if (i == 1 && j == 1) continue;
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][2]);
                dp[i][j][2] = max(dp[i-1][j-1][1], dp[i-1][j][2]) + 1;
            }
            ans = max(dp[i][j][1], ans);
            ans = max(dp[i][j][2], ans);
        }
    }
    ct(ans);
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 