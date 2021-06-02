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
vector<pii> adj[101010];
int minedge[101010][20];
int maxedge[101010][20];


void DFS(int curr) {
    for (auto i: adj[curr]) {
        int next = i.first;
        int cost = i.second;
        if (!check[next]) {
            depth[next] = depth[curr] + 1;
            minedge[next][0] = cost;
            maxedge[next][0] = cost;
            check[next] = 1;
            parent[next][0] = curr;
            DFS(next);
        }
    }
}

pii LCA(int u, int v) {
    int rm = 1010101;
    int rM = 0;
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; diff; i++, diff >>=1) {
        if (diff % 2) {
            rm = min(rm, minedge[u][i]);
            rM = max(rM, maxedge[u][i]);
            u = parent[u][i];
        }
    }
    if (u == v) return {rm, rM};
    for (int j = 19; j >= 0; j--) {
        if (parent[u][j] != parent[v][j]) {
            rm = min(rm, minedge[u][j]);
            rM = max(rM, maxedge[u][j]);
            rm = min(rm, minedge[v][j]);
            rM = max(rM, maxedge[v][j]);
            u = parent[u][j];
            v = parent[v][j];
        }
    }
    rm = min(rm, minedge[u][0]);
    rM = max(rM, maxedge[u][0]);
    rm = min(rm, minedge[v][0]);
    rM = max(rM, maxedge[v][0]);
    return {rm, rM};
}



void solve() {
    cin >> N;
    memset(minedge, 1010101, sizeof(minedge));
    for (int i = 0; i < N-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    check[1] = 1;

    DFS(1);
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
            minedge[i][j] = min(minedge[i][j-1], minedge[parent[i][j-1]][j-1]);
            maxedge[i][j] = max(maxedge[i][j-1], maxedge[parent[i][j-1]][j-1]);
        }
    }


    cin >> Q;

    while (Q--) {
        int a, b; cin >> a>> b;
        tie(a, b) = LCA(a, b);
        ct2(a, b);
    }

}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 