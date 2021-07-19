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
vector<pii> v[101010];
ll ans;

ll f(int curr, int prev) {
    ll temp = 1;
    for (auto next: v[curr]) {
        if (next.first == prev) continue;
        ll tt = f(next.first, curr) * next.second % mod;
        ans += temp * tt; ans %= mod;
        temp += tt; temp %= mod; 
    }
    return temp;

}


void solve() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        int s, e, w; cin >> s >> e >> w;
        v[s].push_back({e, w});
        v[e].push_back({s, w});
    }
    f(1, 0);
    ct(ans);
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 