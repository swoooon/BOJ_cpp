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
int depth[100404];
int parent[100404][20];
int dist[100404];
int check[100404];
vector<pii> adj[100404];
stack<int> st;

void DFS(int a) {
    st.push(a);

    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        for (auto i: adj[curr]) {
            int next = i.first;
            int cost = i.second;
            if (!check[next]) {
                depth[next] = depth[curr] + 1;
                parent[next][0] = curr;
                dist[next] = dist[curr] + cost;
                check[next] = 1;
                st.push(next);
            }
        }
    }


}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int i = 0; diff; i++) {
        if (diff % 2) u = parent[u][i];
        diff /= 2;
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) u = parent[u][i], v = parent[v][i];
    }
    return parent[u][0];
}

void solve() {
    cin >> N;
    cin >> Q;
    check[1] = 1;
    for (int i = 0; i < N-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    DFS(1);
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i  <= N; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
    while (Q--) {
        int a, b; cin >> a >> b;
        cout << dist[a]+dist[b] - 2*dist[LCA(a, b)] << '\n';
    }
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 