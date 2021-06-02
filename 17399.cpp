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
int dist[101010];
int parent[101010][20];
int check[101010];
int depth[101010];
vector<int> adj[101010];


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
    for (int i = 0; diff; i++, diff >>=1) {
        if (diff % 2) u = parent[u][i];
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

int find_cent(int u, int v, int k) {
    int lca_node = LCA(u, v);
    int d = dist[u] + dist[v] - 2*dist[lca_node];
    if (depth[u] < depth[v]) swap(u, v);
    if (d % 2) return -1;
    int cent = 0;
    int diff = d/2;
    for (int i = 0; diff; i++, diff>>=1) {
        if (diff%2) u = parent[u][i];
    }
    if (d/2 == dist[u] + dist[k] - 2*dist[LCA(k, u)]) return u;
    return -1;
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

    while (Q--) {
        int a, b, c; cin >> a>> b>> c;
        int aa = find_cent(a, b, c);
        int bb = find_cent(b, c, a);
        int cc = find_cent(c, a, b);
        if (aa != -1) ct(aa);
        else if (bb != -1) ct(bb);
        else if (cc != -1 ) ct(cc);
        else ct(-1);
    }

}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 