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
vector<int> adj[1010101];
int dp[1010101][2];

int dfs(int now, int cnt, int pre) {
    int &ret = dp[now][cnt];
    if (ret) return ret;
    for (auto next: adj[now]) {
        if (pre != next) {
            int a = dfs(next, 1, now);
            if (cnt) a = min(a, dfs(next, 0, now));
            ret += a;
        }
    }
    if (cnt) ret++;
    return ret;
}


void solve() {
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = min(dfs(1, 0, 0), dfs(1, 1, 0));
    ct(ans);
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 