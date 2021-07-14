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


int N;
int arr[1010];
int dp[1010];

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    int ans = dp[0];
    for (int i = 1; i < N; i++) {
        if (dp[i-1] < 0) dp[i] = arr[i];
        else dp[i] = arr[i] + dp[i-1];
        ans = max(ans, dp[i]);
    }
    ct(ans);
}



int main() {
    FASTIO
    ll T; cin >> T;
    while (T--) solve();
} 