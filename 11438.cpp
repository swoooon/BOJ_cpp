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
int parent[101010][20];
int depth[101010];
vector<int> adj[101010];

void DFS(int curr) {
    for (auto next: adj[curr]) {
        if (depth[next] == -1) {
            parent[next][0] = curr;
            depth[next] = depth[curr] + 1;
            DFS(next);
        }
    }
} 


void solve() {
    cin >> N;
    for (int i = 1; i <= N-1; i++) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(depth, -1, sizeof(depth));
    depth[1] = 0;
    DFS(1);
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }

    cin >> M;
    while (M--) {
        int u, v; cin >> u >> v;
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int j = 0; diff; j++) {
            if (diff % 2) u = parent[u][j];
            diff /= 2;
        }
        if (u != v) {
            for (int j = 19; j >= 0; j--) {
                if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
                    u = parent[u][j];
                    v = parent[v][j];
                }
            }
            u = parent[u][0];
        }
        ct(u);
    }
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 