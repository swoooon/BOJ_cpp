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

int dp[10][3];

int f(int n, int m) {
    if (n == 1) {
        if (m == 0) return 0;
        return 1;
    }
    int &ret = dp[n][m];
    if (ret) return ret;
    return ret = f(n-1, 0) + f(n-1, 1) + f(n-1, 2);
}

void solve() {
    int N; cin >> N;
    ct(f(N, 0));
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 