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

int N, M;
int arr[303][303];
int dp[303][303];

int f(int y, int x) {
    if (y == 0 && x == 0) return 0;
    int &ret = dp[x][y];
    if (ret != -1) return ret;
    if (y-1 >= 0) ret = max(ret, f(y-1, x));
    if (x-1 >= 0) ret = max(ret, f(y, x-1));
    if (arr[x][y]) ret += max(M-x-y,0);
    return ret;
}

void solve() {
    cin >> N >> M;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a>> b;
        arr[a][b]++;
    }
    ct(f(300, 300));
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 