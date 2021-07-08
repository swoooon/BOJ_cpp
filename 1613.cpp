#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
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


int N, M, Q;
int adj[404][404];

void FW() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (adj[j][i] == -1 && adj[i][k] == -1) adj[j][k] = -1;
                if (adj[j][i] == 1 && adj[i][k] == 1) adj[j][k] = 1;
            }
        }
    }
}

void solve() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a][b] = -1;
        adj[b][a] = 1;
    }
    cin >> Q;
    FW();
    while (Q--) {
        int a, b; cin >> a>> b;
        ct(adj[a][b]);
    }
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 