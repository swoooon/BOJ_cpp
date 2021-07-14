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


ld arr[10101];
int N;
ld dp[10101];

void solve() {
    cout << fixed;
    cout.precision(3);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    ld ans = arr[0];
    dp[0] = arr[0];
    for (int i = 1; i < N; i++) {
        if (dp[i-1] < 1) dp[i] = arr[i];
        else dp[i] = dp[i-1]*arr[i];
        ans = max(ans, dp[i]);
    }
    ct(ans);
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 