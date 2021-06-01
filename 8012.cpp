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

int N, Q;
int dist[30303];
int parent[30303][20];
int check[30303];
int depth[30303];
vector<int> adj[30303];


void DFS(int curr) {
    for (auto next: adj[curr]) {
        if (!check[next]) {
            depth[next] = depth[curr] + 1;
            dist[next] = dist[curr] + 1;
            check[next] = 1;
            parent[next][0] = curr;
            DFS(next);
        }
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; diff; i++) {
        if (diff % 2) u = parent[u][i];
        diff/=2;
    }
    if (u == v) return u;
    for (int j = 19; j >= 0; j--) {
        if (parent[u][j] != parent[v][j]) {
            u = parent[u][j];
            v = parent[v][j];
        }
    }
    return parent[u][0];
}


void solve() {
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    check[1] = 1;

    DFS(1);
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }


    cin >> Q;
    ll ans = 0;
    int pre = 1;
    while (Q--) {
        int a; cin >> a;
        ans += dist[a] + dist[pre] - 2*dist[LCA(a, pre)];
        pre = a;
    }
    ct(ans);

}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 