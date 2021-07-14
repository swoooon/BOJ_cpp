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


ll N, L, K;
ll dp[33][33];


ll f(ll i, ll j) {
    if (j == L || i >= N) return 1;
    if (dp[i][j]) return dp[i][j];
    return dp[i][j] = f(i+1, j) + f(i+1, j+1);
}

void solve() {
    cin >> N >> L >> K;
    ll j = 0;
    for (ll i = 1; i <= N; i++) {
        ll a = f(i, j);
        if (K > a) {
            K -= a;
            j++;
            cout << "1";
        }
        else {
            cout << "0";
        }
    }

}
 


int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 