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

ll check[101010];
ll parent[101010][20];
ll depth[101010];
ll dist[101010];
vector<pii> adj[101010];
ll N, Q;

void DFS(ll curr) {
    for (auto i: adj[curr]) {
        ll next = i.first;
        ll cost = i.second;
        if (!check[next]) {
            depth[next] = depth[curr] + 1;
            check[next] = 1;
            dist[next] = dist[curr] + cost;
            parent[next][0] = curr;
            DFS(next);
        }
    }
}

ll LCA(ll u, ll v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; diff; i++, diff >>= 1) {
        if (diff%2) u = parent[u][i];
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

ll query2(ll u, ll v, ll k) {
    k--;
    int cent = LCA(u, v);
    if (k <= depth[u] - depth[cent]) {
        int diff = k;
        for (int i = 0; diff; i++, diff>>=1) {
            if (diff%2) u = parent[u][i];
        }
        return u;
    }
    else {
        int diff = depth[u] + depth[v] - 2*depth[cent] - k;
        for (int i = 0; diff; i++, diff>>=1) {
            if (diff%2) v = parent[v][i];
        } 
        return v;
    }
}


void solve() {
    cin >> N;
    for (ll i = 0; i < N-1; i++){
        ll a, b, c; cin >> a>> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    check[1] = 1;
    DFS(1);
    for (ll j = 1; j < 20; j++) {
        for (ll i = 1; i <= N; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
    cin >> Q;
    while (Q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int a, b; cin >> a>> b;
            ct(dist[a] + dist[b] - 2*dist[LCA(a, b)]);
        }
        else {
            int a, b, c; cin >> a>> b>> c;
            ct(query2(a, b, c));
        }
    }
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 